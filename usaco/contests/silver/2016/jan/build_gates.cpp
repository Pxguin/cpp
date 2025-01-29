#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int M = 2002;
bool vis[M][M];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
    
    int n; cin >> n;
    v<char> c(n);
    pii p = {0,0}, mn = {0,0};
    F0R(i,n) {
        cin >> c[i];
        p.f += (c[i]=='N')-(c[i]=='S');
        p.s += (c[i]=='E')-(c[i]=='W');
        chmin(mn.f,p.f); chmin(mn.s,p.s); // normalize position to positive coordinates only (avoid mle?)
    }
    p = {1-2*mn.f,1-2*mn.s};
    F0R(i,n) {
        if (c[i]=='N') {vis[++p.f][p.s]=vis[++p.f][p.s]=true;} // double length of fence
        else if (c[i]=='S') {vis[--p.f][p.s]=vis[--p.f][p.s]=true;}
        else if (c[i]=='W') {vis[p.f][--p.s]=vis[p.f][--p.s]=true;}
        else {vis[p.f][++p.s]=vis[p.f][++p.s]=true;}
    }
    int ans = 0;
    F0R(i,M) {
        F0R(j,M) {
            if (!vis[i][j]) {
                stack<pii> s; s.push({i,j});
                while (s.size()) { // iterative flood fill
                    auto[i,j] = s.top(); s.pop();
                    if (i==-1||i==M||j==-1||j==M||vis[i][j]) {continue;}
                    vis[i][j] = true;
                    s.push({i+1,j}); s.push({i-1,j});
                    s.push({i,j+1}); s.push({i,j-1});
                }
                ans++;
            }
        }
    } cout << ans-1 << '\n';
}