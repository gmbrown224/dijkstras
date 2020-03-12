#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {

	size_t tiles;
	int one, two;
	map <char, int> terrain;
	map <char, int>::iterator ptr;	//map for tiles
	vector <vector <char> > map;	//vector for storing the characters
	istringstream iss;
	ofstream fout;					//output file stream

	if (argc != 2) {
		cerr << "usage: ./generate_map [Number of Tiles]\n";
		return -1;
	}
	iss.str(argv[1]);
	iss >> tiles;

	for (size_t i = 0; i < tiles; i++) {
		vector<char> tempvec;
		for (size_t j = 0; j < tiles; j++) {		//making a randomized map and putting every
			srand(time(NULL) - (i + (j * j)));		//char into a map with a cost value
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

	fout.open("input");
	fout << terrain.size() << '\n';
	for (ptr = terrain.begin(); ptr != terrain.end(); ptr++)
		fout << ptr->first << ' ' << ptr->second << '\n';
	fout << tiles << ' ' << tiles << '\n';
	for (size_t i = 0; i < map.size(); i++) {		//formatting all the data into input file
		for (size_t j = 0; j < map.size(); j++) {
			fout << map[i][j] << ' ';
		}
		fout << '\n';
	}
	fout << "0 0\n";
	srand(time(NULL));
	int q = 0;
	while (true) {
		one = (rand() + q) % tiles;
		two = (one + ((rand() * rand()) + q)) % tiles;
		if (one != 0 && two != 0) break;
		q++;										//get a ending point that isn't the starting point
	}
	fout << one << ' ' << two << '\n';

	return 0;
}
