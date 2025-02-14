#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    v<pii> s(n);
    F0R(i,n) {s[i] = {a[i],i};}
    sort(all(s));
    while (s.size()) { // sort each group
        v<int> idx;
        F0R(i,k) {
            idx.pb(s[s.size()-i-1].s);
        } sort(all(idx));
        F0R(i,k) {
            a[idx[k-i-1]] = s.back().f;
            s.pop_back();
        }
    }
    v<int> dp; // calculate lis
    for (int i : a) {
        int pos = lower_bound(dp.begin(),dp.end(),i)-dp.begin();
        if (pos==dp.size()) {dp.pb(i);}
        else {dp[pos]=i;}
    }
    cout << n-dp.size() << '\n';
}