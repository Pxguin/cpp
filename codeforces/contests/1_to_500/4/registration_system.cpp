#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    map<string,int> m;
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        string s; cin >> s;
        if (m.count(s)) {cout << s << m[s] << '\n';}
        else {cout << "OK\n";}
        m[s]++;
    }
}