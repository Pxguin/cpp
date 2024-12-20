#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("reduce.in","r",stdin);
    freopen("reduce.out","w",stdout);
    
    int n; cin >> n;
    v<v<int>> x(40002), y(40002);
    v<int> l, u, r, d;
    F0R(i,n) {
        int a, b; cin >> a >> b;
        x[a].pb(i); y[b].pb(i);
    }
    l.pb(0); r.pb(40001); u.pb(40001); d.pb(0);
    F0R(i,40001) { // basically coordinate compression
        if (x[i].size()) {l.pb(i);}
        if (y[i].size()) {d.pb(i);}
        if (x[40000-i].size()) {r.pb(40000-i);}
        if (y[40000-i].size()) {u.pb(40000-i);}
    }

    ll ans = (r[1]-l[1])*(u[1]-d[1]);
    F0R(left,min(4,(int)l.size())) { // left border
        F0R(up,min(4,(int)u.size())) { // right
            F0R(right,min(4,(int)r.size())) { // top
                F0R(down,min(4,(int)d.size())) { // bottom
                    if (l[left]>r[right]||d[down]>u[up]) {continue;}

                    unordered_set<int> cows;
                    F0R(j,left+1) {for (int i : x[l[j]]) {cows.insert(i);}} // add removed cows
                    F0R(j,right+1) {for (int i : x[r[j]]) {cows.insert(i);}}
                    F0R(j,up+1) {for (int i : y[u[j]]) {cows.insert(i);}}
                    F0R(j,down+1) {for (int i : y[d[j]]) {cows.insert(i);}}
                    
                    if (cows.size()>3) {continue;} // removed cows needs to be <= 3
                    chmin(ans,(ll)(r[right+1]-l[left+1])*(u[up+1]-d[down+1])); // new area of enclosure
                }
            }
        }
    } cout << ans << '\n';
}