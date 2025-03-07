#include <bits/stdc++.h>
using namespace std;

map<char,char> m = {{'q','p'},{'w','w'},{'p','q'}}; // what does each character map to

void solve() {
    string s; cin >> s;
    for (int i=s.size()-1;i>=0;i--) {cout << m[s[i]];}
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}