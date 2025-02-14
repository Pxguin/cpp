#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("dishes.in","r",stdin);
    freopen("dishes.out","w",stdout);
    
    int n; cin >> n;
    v<int> p(n);
    F0R(i,n) {cin >> p[i]; p[i]--;}

    auto check = [&](int m) {
        v<int> comp(n), left(n);

        v<int> vis(n,-1), order;
        F0R(i,m) {vis[p[i]] = i;}
        int last = n;
        F0R(i,n) { // find which stack to put it on
            if (vis[i]!=-1) {order.pb(vis[i]);}
            if (vis[n-i-1]!=-1) {
                left[vis[n-i-1]] = (last<vis[n-i-1] ? last : -1);
                last = min(last,vis[n-i-1]);
            }
        }
        
        v<stack<int>> dishes;
        int ptr = 0, done = 0;
        F0R(i,m) {
            if (left[i]==-1) { // greedy strategy and check if it's possible
                comp[i] = dishes.size();
                dishes.pb(stack<int>());
                dishes.back().push(i);
            } else {dishes[comp[i]=comp[left[i]]].push(i);}

            while (ptr!=dishes.size()) {
                if (dishes[ptr].empty()) {ptr++;}
                else if (dishes[ptr].top()==order[done]) {
                    dishes[ptr].pop(); done++;
                } else {break;}
            }
        }
        return (done==m);
    };

    int l = 0, h = n-1, m = (l+h)/2, ans;
    while (l <= h) {
        if (check(m)) {
            l = m+1; ans = m;
        } else {h = m-1;}
        m = (l+h)/2;
    } cout << ans << '\n';
}