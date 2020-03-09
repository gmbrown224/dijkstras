//Graham Brown
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

class Dijk {
	public: 
		Dijk(int argc, char **argv);
		vector<int> board;
		map<char, int> terrain;
		int r;
		int c;
		int start;
		int goal;

		int recurDijk(int index, int target, int moves);
};

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

    return 0;
}

int Dijk::recurDijk(int index, int target, int moves){



	return board[index];
}
