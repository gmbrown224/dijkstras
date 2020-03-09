//Graham Brown, Hasan Tiwana
//Project 4
//This lab takes a board and finds the cheapest route between two points

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>

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
		multimap<int, Node *>::iterator spot_in_mm; //from TA
};
//this has not been implemented at all, i only used my dijk class so far
//but i was planning on using dijk class for mostly everything unless we
//find an issue and we need the node class to solve the problem
//set backedge of last to null

class Dijk {
	public: 
		Dijk(int argc, char **argv);
		vector<int> board;
		vector<vector<Node *> > grid;
		map<char, int> terrain;
		int r;
		int c;
		int start;
		int goal;

		int recur_dijk(int index);
};

//vector of vector with a node class

Dijk::Dijk(int argc, char **argv) {

	char type;
	string read, hold;
	int temp, val;
	istringstream iss;

	cin >> temp;
	for (int i = 0; i < temp + 1; i++) {
		getline(cin, read);
		if (read != "") {
			iss.clear();
			iss.str(read);
			iss >> type >> val;
			terrain.insert(make_pair(type, val));
		}
	}
	
	cin >> temp >> val;
	r = temp;
	c = val;
	board.resize(r * c);
	for (int j = -1; j < r; j++) {
		getline(cin, read);
		if (read != "")
			for (int q = 0; q < c; q++)
				board[(j * c) + q] = read[2 * q];
	}

	cin >> temp >> val;
	start = (temp * c) + val;
	cin >> temp >> val;
	goal = (temp * c) + val;

	return;
}

int main(int argc, char *argv[]) {

	Dijk *d = new Dijk(argc, argv);

	for (size_t i = 0; i < d->board.size(); i++) { //testing to show board input is correct
		cout << (char) d->board[i] << ' ';
		if (((int) i % d->c) == (d->c - 1)) cout << '\n';
	}

    return 0;
}

int Dijk::recur_dijk(int index){	//maybe use recursion? not sure, but my idea was
									//to search down each direction and return the cheapest
									//value. the parent will choose the cheaper option
									//and then add it to themselves. the origin call will
									//then make the final comparison to find overall cheapest
	if (index == goal) return 0;

	int hori = recur_dijk(index + 1);
	int vert = recur_dijk(index + c);
	map<char, int>::iterator ptr = terrain.find((char) board[index]);
	if (hori < vert)
		return ptr->second + hori;
	else
		return ptr->second + vert;
}
