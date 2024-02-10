#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
unordered_set<char> x;
 
bool solve() {
	char c; cin >> c;
	
	return x.count(c);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	string s = "codefrs";
	for (char c : s) {x.insert(c);}
	while (t--) {cout << (solve() ? "YES" : "NO") << "\n";}
}