#include <bits/stdc++.h>
#include <string>

using namespace std;

void get_pair(string, string*, string*);
int count_orbits(map<string, string>&, map<string, int>&, string);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;

    map<string, string> orbits;
    map<string, int> counts;
    string* inner;
    string* outer;
    while(getline(cin, line)) {
	get_pair(line, inner, outer);
	orbits.emplace(*outer, *inner);
	delete inner;
	delete outer;
    }

    int total_count = 0;
    for(auto& pair: orbits) {
	total_count += count_orbits(orbits, counts, pair.first);
    }

    cout << total_count << endl;
}

void get_pair(string input, string* inner, string* outer) {
    string text = "";
    for(auto it = input.begin(); it <= input.end(); ++it) {
	if (*it == ')') {
	    inner = new string(text);
	} else if(it == input.end()) {
	    outer = new string(text);
	} else {
	    text += *it;
	}
    }
}

int count_orbits(map<string, string>& orbits, map<string, int>& counts, string planet) {
    auto exists_it = counts.find(planet);

    // if we have already calculated our value
    if(exists_it != counts.end()) {
	return counts.at(planet);
    }

    // if not, we need to calculate it.
    
    // if our planet does not orbit anything, we return 0.
    auto does_orbit_it = orbits.find(planet);
    if(does_orbit_it == orbits.end()) {
	counts.emplace(planet, 0);
	return 0;
    }

    //finally, if our planet does orbit something, we get its other orbits and add 1.
    string parent_planet = orbits.at(planet);
    int count = count_orbits(orbits, counts, parent_planet) + 1;
    counts.emplace(planet, count);
    return count;
}
