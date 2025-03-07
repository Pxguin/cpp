#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

int solve() {
    int n, m; cin >> n >> m;
    vec<vec<int>> adj1(n), adj2(n);
    vec<int> color(n,-1);
    F0R(i,m) {
        int t, a, b; cin >> t >> a >> b;
        a--; b--;
        if (t==1) {adj1[a].pb(b); adj1[b].pb(a);} // must be different
        else {adj2[a].pb(b); adj2[b].pb(a);} // must be same
    }
    int ans = 0;

    F0R(i,n) {
        if (color[i]==-1) { // new component
            color[i] = 0; // color arbitrarily
            int tot[2] = {1,0};
            stack<int> todo; todo.push(i);

            while (todo.size()) {
                int cur = todo.top(); todo.pop();
                for (int x : adj1[cur]) { // go through amongi needing to be different color
                    if (color[x]==-1) { // if it isn't colored then it's ok
                        color[x] = !color[cur];
                        tot[color[x]]++;
                        todo.push(x);
                    } else if (color[x]==color[cur]) {return -1;} // fail case: it's already colored with the wrong color
                }
                for (int x : adj2[cur]) { // go through all amongi that need to be same color
                    if (color[x]==-1) {
                        color[x] = color[cur];
                        tot[color[x]]++;
                        todo.push(x);
                    } else if (color[x]!=color[cur]) {return -1;}
                }
            }
            if (tot[0]<tot[1]) {swap(tot[0],tot[1]);} // zero = parasite, maximize # parasites
            ans += tot[0];
        }
    } return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {cout << solve() << '\n';}
}