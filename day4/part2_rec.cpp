#include <bits/stdc++.h>
#include <string>

using namespace std;

int* get_range(string input);
int rec(int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input_str;
    cin >> input_str;


    int* range = get_range(input_str);

    int count = 0;
    count = rec(3, 6, 5);
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

int rec(int a, int b, int d) {
    int new_b = 9;
    if(d == 1) {
	return b-a+1;
    }
    int sum = 0;
    for(int i = a; i <= b; i++) {
	sum += (i-a+1)*rec(i,new_b,d-1);
    }
    return sum;
}
