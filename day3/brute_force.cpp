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
bool compare_segs (const Segment* first, const Segment* second);

int main() {
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);

    list<Segment*> h_segs;
    list<Segment*> v_segs;
    
    string wire1;
    cin >> wire1; 

    Coord* last_coord = new Coord(0, 0);
    bool first = true;
    char dir;
    string dist_str = "";
    for (auto it = wire1.begin(); it <= wire1.end(); ++it) {
	char c = *it;
	if (c == ',' || it == wire1.end()) {
	    first = true;
	    Coord* new_coord;
	    int dist = atoi(dist_str.c_str());
	    if(dir == 'U') {
		new_coord = new Coord(last_coord->x, last_coord->y+dist);
		v_segs.push_back(new Segment(last_coord->y, new_coord->y, new_coord->x));
	    } else if(dir == 'D') {
		new_coord = new Coord(last_coord->x, last_coord->y-dist);
		v_segs.push_back(new Segment(new_coord->y, last_coord->y, new_coord->x));
	    } else if(dir == 'L') {
		new_coord = new Coord(last_coord->x-dist, last_coord->y);
		h_segs.push_back(new Segment(new_coord->x, last_coord->x, new_coord->y));
	    } else if(dir == 'R') {
		new_coord = new Coord(last_coord->x+dist, last_coord->y);
		h_segs.push_back(new Segment(last_coord->x, new_coord->x, new_coord->y));
	    }
	    delete last_coord;
	    last_coord = new_coord;
	    dist_str = "";
	} else if(first) {
	    dir = c;
	    first = false;
	} else {
	    dist_str += c;
	}
    }
    h_segs.sort(compare_segs);
    v_segs.sort(compare_segs);
    cout << "h: " << endl;
    for (auto it = h_segs.begin(); it != h_segs.end(); ++it) {
	cout << (*it)->min << " " << (*it)->max << " " << (*it)->pos << endl;
    }
    
    cout << "v: " << endl;    
    for (auto it = v_segs.begin(); it != v_segs.end(); ++it) {
	cout << (*it)->min << " " << (*it)->max << " " << (*it)->pos << endl;
    }
    delete last_coord;
}

bool compare_segs (const Segment* first, const Segment* second) {
    if (first->pos < second->pos) return true;
    else return false;
}
