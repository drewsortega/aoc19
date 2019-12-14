#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Segment {
public:
    Segment(int min, int max, int pos) : min(min), max(max), pos(pos) {}
    int min;
    int max;
    int pos;
};

class Coord {
public:
    Coord(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

bool compare_segs (const Segment* first, const Segment* second);


struct segcomp {
    bool operator() (const Segment* l, const Segment* r) const {
	return compare_segs(l, r);
    }
};

struct Wire {
    set<Segment*, segcomp> h_segs;
    set<Segment*, segcomp> v_segs;
};
Wire parse_wire(string wire_txt);

int main() {
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);
    
    string wire1_txt;
    cin >> wire1_txt; 

    string wire2_txt;
    cin >> wire2_txt; 

    Wire wire1 = parse_wire(wire1_txt);
    Wire wire2 = parse_wire(wire2_txt);

    list<Coord> intersections;

    int best = 100000000;
     
    for(auto it1 = wire1.v_segs.begin(); it1 != wire1.v_segs.end(); ++it1) {

	Segment* s1 = *it1;
	cout << s1->min << " " << s1->max << " " << s1->pos << endl;
	for(auto it2 = wire2.h_segs.begin(); it2 != wire2.h_segs.end(); ++it2) {
	    Segment* s2 = *it2;
	    if( (
		    s1->pos >= s2->min 
		    && s1->pos <= s2->max 
		    && s2->pos >= s1->min
		    && s2->pos <= s1->max )) {
		int d = abs(s1->pos) + abs(s2->pos);
		if(d < best) {
		    best = d;
		}
	    }
	}
    }
    for(auto it1 = wire1.h_segs.begin(); it1 != wire1.h_segs.end(); ++it1) {
	Segment* s1 = *it1;
	cout << s1->min << " " << s1->max << " " << s1->pos << endl;
	for(auto it2 = wire2.v_segs.begin(); it2 != wire2.v_segs.end(); ++it2) {
	    Segment* s2 = *it2;
	    if(s1->pos >= s2->min 
		    && s1->pos <= s2->max 
		    && s2->pos >= s1->min
		    && s2->pos <= s1->max ) {
		int d = abs(s1->pos) + abs(s2->pos);
		if(d < best) {
		    best = d;
		}
	    }
	}
    }

    cout << best << endl;

}

bool compare_segs (const Segment* first, const Segment* second) {
    if (first->pos == second->pos) {
	if(first->min == second->min) {
	    if (first->max < second->max) return true;
	} else if (first->pos < second->pos) return true;
    } else if (first->pos < second->pos) return true;
    return false;
}

Wire parse_wire(string wire_txt) {
    set<Segment*, segcomp> h_segs;
    set<Segment*, segcomp> v_segs;

    Coord* last_coord = new Coord(0, 0);
    bool first = true;
    char dir;
    string dist_str = "";
    for (auto it = wire_txt.begin(); it <= wire_txt.end(); ++it) {
	char c = *it;
	if (c == ',' || it == wire_txt.end()) {
	    first = true;
	    Coord* new_coord;
	    int dist = atoi(dist_str.c_str());
	    if(dir == 'U') {
		new_coord = new Coord(last_coord->x, last_coord->y+dist);
		v_segs.insert(new Segment(last_coord->y, new_coord->y, new_coord->x));
	    } else if(dir == 'D') {
		new_coord = new Coord(last_coord->x, last_coord->y-dist);
		v_segs.insert(new Segment(new_coord->y, last_coord->y, new_coord->x));
	    } else if(dir == 'L') {
		new_coord = new Coord(last_coord->x-dist, last_coord->y);
		h_segs.insert(new Segment(new_coord->x, last_coord->x, new_coord->y));
	    } else if(dir == 'R') {
		new_coord = new Coord(last_coord->x+dist, last_coord->y);
		h_segs.insert(new Segment(last_coord->x, new_coord->x, new_coord->y));
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

    delete last_coord;

    return Wire {
	h_segs,
	v_segs
    };
}
