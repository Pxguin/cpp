#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
    string s; cin >> s;
    int ans = 0;
    F0R(i,s.size()-1) { // you can end up reducing string to length 1 if any reduction is possible from initial string
        ans |= (s[i]==s[i+1]);
    }
    cout << (ans ? 1 : s.size()) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}