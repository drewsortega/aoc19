#include <bits/stdc++.h>
#include <string>

using namespace std;

int* get_range(string input);
bool is_valid(int key);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input_str;
    cin >> input_str;


    int* range = get_range(input_str);

    int count = 0;
    for(int i = range[0]; i <= range[1]; i++) {
	if(is_valid(i)) count++;
    }
    cout << count << endl;
}

int* get_range(string input) {
    string num_str = "";
    int index = 0;
    int* range = new int[2];
    for(auto it = input.begin(); it <= input.end(); ++it) {
	if (it == input.end() || *it == '-') {
	    range[index++] = atoi(num_str.c_str());
	    num_str = "";
	} else {
	    num_str += *it;
	}
    }
    return range;
}

bool is_valid(int key) {
    bool valid = true;
    bool has_double = false;
    bool double_locked = false;
    bool can_double = true;
    int current_digit = key % 10;
    int next_digit;
    while(valid) {
	key = key / 10;
	next_digit = key % 10;
	if(key == 0) {
	    return (valid && (double_locked || has_double));
	}
	if(next_digit == current_digit) {
	    if(has_double) {
		has_double = false;
		can_double = false;
	    } else if(can_double) {
		has_double = true;
	    }
	} else if (current_digit < next_digit) {
	    valid = false;
	} else {
	    if(has_double) {
		double_locked = true;
	    }
	    has_double = false;
	    can_double = true;
	}
	current_digit = next_digit;
    }
    return false;
}
