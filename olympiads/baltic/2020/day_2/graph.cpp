#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 1e5;
vec<pii> adj[MAX_N];
int ans[MAX_N];
int col[MAX_N] = {0};
vec<pii> comps;
vec<vec<int>> comps2;

void dfs(int cur, int color) {
    col[cur] = color+1;
    comps2.back().pb(cur);
    for (auto[x,c] : adj[cur]) {
        if (!col[x]) {
            ans[x] = c-ans[cur];
            dfs(x,!color);
        } else {
            if (col[x]==col[cur]) { // if odd cycle, then one or zero solution
                comps.back().f = cur;
                comps.back().s = (c-ans[cur]-ans[x])/2;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[--a].pb({--b,2*c});
        adj[b].pb({a,2*c});
    }
    for (int i=0;i<n;i++) {
        if (!col[i]) {
            comps.pb({-1,-1});
            comps2.pb({});
            dfs(i,0);
        }
    }
    for (int c=0;c<comps.size();c++) { // for each component
        auto[rt,delta] = comps[c];
        if (rt==-1) {
            rt = comps2[c][0];
            vec<int> idx;
            for (int i : comps2[c]) { // take the median to minimize abs sum
                if (col[i]==col[rt]) {idx.pb(-ans[i]);}
                else {idx.pb(ans[i]);}
            }
            sort(all(idx));
            delta = idx[(idx.size()-1)/2];
        }
        for (int i : comps2[c]) {
            ans[i] += (col[i]==col[rt] ? 1 : -1)*delta; // shift all by the median if no odd cycle; otherwise, follow odd cyc procedure
        }
    }

    bool flag = false;
    for (int i=0;i<n;i++) {
        for (auto[x,c] : adj[i]) {
            if (ans[x]+ans[i]!=c) {flag = true;}
        }
    }

    if (flag) {cout << "NO\n";}
    else {
        cout << "YES\n";
        cout << fixed << setprecision(1);
        for (int i=0;i<n;i++) {
            cout << (double)ans[i]/2 << ' ';
        }
    }

}