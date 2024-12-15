#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cowcode.in","r",stdin);
    freopen("cowcode.out","w",stdout);

    string s; cin >> s;
    ll n; cin >> n;
    ll cur = s.size();

    while (cur<n) {cur *= 2;} // # of doublings
    n--;
    while (cur>s.size()) { // repeat until we have the position in the original string
        cur /= 2;
        if (n>=cur) { // map to the position in the last doubling
            n = ((n-1)+cur)%cur;
        }
    }
    cout << s[n] << '\n';
}