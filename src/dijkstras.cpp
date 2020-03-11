// dijsktras.cpp

#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

class Node {
	public:
		int x;
		int y;
		int weight;
		int distance;
		char type;

		bool visited;
		Node *backedge;
		vector<Node *> adj;
		multimap<int, Node *>::iterator spot_in_mm;
};

class Dijk {
	public:
		Dijk(int argc, char **argv, multimap<int, Node *> unvisited);
		vector<Node *> grid;
		map<char, int> terrain;
		int r;
		int c;
		int start;
		int goal;
};

Dijk::Dijk(int argc, char **argv, multimap<int, Node *> unvisited) {
	
	char type;
	int temp, val;
	string line;
	stringstream ss;

	cin >> temp;
	getline(cin, line);
	for (int i = 0; i < temp; i++) {
		getline(cin, line);
		ss.clear();
		ss.str(line);
		while (ss >> type >> val)
			terrain.insert({type, val});
	}

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			Node *n = new Node();
			n->x = i;
			n->y = j;
			n->distance = -1;
			cin >> n->type;
			n->weight = terrain.find(n->type)->second;
			n->visited = false;
			n->backedge = nullptr;
			n->spot_in_mm = unvisited.end();
			grid.push_back(n);
		}
	}

	for (int i = 0; i < (int) grid.size(); i++) {
		if (i % c != (c-1))
			grid[i]->adj.push_back(grid[i+1]);

		if (i % c != 0)
			grid[i]->adj.push_back(grid[i-1]);

		if (i - c >= 0)
			grid[i]->adj.push_back(grid[i-c]);

		if (i + c < (int) grid.size())
			grid[i]->adj.push_back(grid[i+c]);
	}

	cin >> temp >> val;
	start = (temp * c) + val;
	cin >> temp >> val;
	goal = (temp * c) + val;

	return;
}


int main(int argc, char *argv[]) {

	Dijk *d;

	multimap<int, Node *> path;
	multimap<int, Node *>::iterator mit;
	int dist, cost;
	Node *n, *n2;

	d = new Dijk(argc, argv, path);

	// start at source node, set distance to 0 and add to multimap
	n = d->grid[d->start];
	n->distance = 0;
	n->spot_in_mm = path.insert({n->distance, n});

	while (path.size() > 0) {
		// find node with smallest distance from source,
		// remove from multimap and set visited to true
		n = path.begin()->second;
		path.erase(n->spot_in_mm);
		n->spot_in_mm = path.end();
		n->visited = true;

		// for each unvisited adjacent node
		for (int i = 0; i < (int) n->adj.size(); i++) {
			n2 = n->adj[i];
			if (n2->visited == false) {
				// set distance of adjacent node
				dist = n->distance + n2->weight;
				// set new distance or replace with smaller path distance
				if (n2->distance == -1 || dist < n2->distance) {
					// remove n2 if it is in the multimap
					mit = path.find(n2->distance);
					while (mit != path.end()) {
						if (mit->first == n2->distance && mit->second == n2)
							path.erase(mit++);
						else
							mit++;
					}
					n2->distance = dist;
					n2->backedge = n;
					n2->spot_in_mm = path.insert({n2->distance, n2});
				}
			}
		}
	}

	// should print output backwards (untested)
	path.clear();
	cost = 0;

	n = d->grid[d->goal];
	while (n != nullptr) {
		if (n != d->grid[d->goal])
			cost += n->weight;
		path.insert({n->distance, n});
		n = n->backedge;
	}

	cout << cost << endl;

	for (mit = path.begin(); mit != path.end(); mit++)
		cout << mit->second->x << ' ' << mit->second->y << endl;

	for (int i = 0; i < (int) d->grid.size(); i++)
		delete d->grid[i];

	delete d;

    return 0;
}

