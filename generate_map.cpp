#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {

	size_t tiles;
	map <char, int> terrain;
	map <char, int>::iterator ptr;
	vector <vector <char> > map;
	istringstream iss;

	if (argc != 2) {
		cerr << "usage: ./generate_map [Number of Tiles]\n";
		return -1;
	}
	iss.str(argv[1]);
	iss >> tiles;

	for (size_t i = 0; i < tiles; i++) {
		vector<char> tempvec;
		for (size_t j = 0; j < tiles; j++) {
			srand(time(NULL) - (i + (j * j)));
			char temp = (rand() % 26) + 97;
			int cost = ((rand() + (j*j)) % 10) + 1;
			ptr = terrain.find(temp);
			if (ptr == terrain.end())
				terrain.insert(make_pair(temp, cost));
			else
				cost = ptr->second;
			tempvec.push_back(temp);
		}
		map.push_back(tempvec);
	}

	for (size_t i = 0; i < map.size(); i++) {
		for (size_t j = 0; j < map.size(); j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	for (ptr = terrain.begin(); ptr != terrain.end(); ptr++) {
		cout << ptr->first << " = " << ptr->second << '\n';
	}

	return 0;
}
