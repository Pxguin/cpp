#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int h, w; cin >> h >> w;
    F0R(i,h) {
        v<char> c(w);
        F0R(j,w) { // read in one row
            cin >> c[j];
        }
        F0R(k,2) { // print out same row, twice
            F0R(j,w) {cout << c[j];}
            cout << '\n';
        }
    }
}