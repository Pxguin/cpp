#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n), b(n);
    F0R(i,n) {cin >> a[i] >> b[i];}
    map<int,int> freq; // frequency array
    F0R(i,n) {freq[b[i]]++;}

    ll ans = 0;
    F0R(i,n) {ans += (ll)a[i]*freq[a[i]];}
    cout << ans << '\n';
}