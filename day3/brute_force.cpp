#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class Coord {
public:
    Coord(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

class Segment {
public:
    Segment(int min, int max, int pos) : min(min), max(max), pos(pos) {}
    int min;
    int max;
    int pos;
};
int main() {
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);

    list<Segment> h_segs;
    list<Segment> v_segs;
    
    char* wire1;
    cin >> wire1; 

    Coord* last_coord = new Coord(0, 0);

    char* token;
    const char delim = ',';
    token = strtok(wire1, delim);
    while (token != NULL) {
	char dir = token[0];
	int distance = atoi(token + 1);

	Coord* new_coord;

	if(dir == 'U') {
	    v_segs.push_back(Segment(last_coord->y, last_coord->y+distance, last_coord->x));
	    new_coord = new Coord(last_coord->x, last_coord->y+distance);
	} else if(dir == 'D') {
	    v_segs.push_back(Segment(last_coord->y-distance, last_coord->y, last_coord->x));
	    new_coord = new Coord(last_coord->x, last_coord->y-distance);
	} else if(dir == 'L') {
	    h_segs.push_back(Segment(last_coord->x-distance, last_coord->x, last_coord->y));
	    new_coord = new Coord(last_coord->x-distance, last_coord->y);
	} else if(dir == 'R') {
	    h_segs.push_back(Segment(last_coord->x, last_coord->x+distance, last_coord->y));
	    new_coord = new Coord(last_coord->x+distance, last_coord->y);
	}

	delete last_coord;
	last_coord = new_coord;
	 
	token = strtok(NULL, delim);
    }
    for(std::list<Segment>::iterator it=h_segs.begin(); it != h_segs.end(); ++it) {
	cout << it->min << " " << it->max << " " << it->pos << endl;
    }
}
