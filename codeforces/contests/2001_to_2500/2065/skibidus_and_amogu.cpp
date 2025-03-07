#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    cout << s.substr(0,s.size()-2) << 'i' << '\n'; // remove last two characters and add "i"
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}