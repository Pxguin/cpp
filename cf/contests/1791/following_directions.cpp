#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
bool solve() {
	int n; cin >> n;
	int x = 0, y = 0;
	string s; cin >> s;
	for (char z : s) {
	    switch(z) {
	        case 'U':
	            y++; break;
	        case 'D':
	            y--; break;
	        case 'L':
	            x--; break;
	        case 'R':
	            x++; break;
	    }
	    if (x == 1 && y == 1) {return true;}
	}
	return false;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {cout << (solve() ? "YES" : "NO") << "\n";}
}