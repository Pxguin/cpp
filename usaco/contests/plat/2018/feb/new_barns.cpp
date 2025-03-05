#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 1e5, l2d = 18;
int lift[l2d][MAX_N], depth[MAX_N] = {0}, comp[MAX_N];
pii diam[MAX_N];

int jump(int a, int d) {
    F0R(i,l2d) {
        if ((1<<i)&d) {a = lift[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (depth[a]<depth[b]) {swap(a,b);}
    a = jump(a,depth[a]-depth[b]);
    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (lift[i][a]!=lift[i][b]) {
            a = lift[i][a];
            b = lift[i][b];
        }
    } return lift[0][a];
}

int dist(int a, int b) {
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}

void cmp(pii&a, pii b) { // take the better candidate for the diameter
    if (dist(a.f,a.s)<dist(b.f,b.s)) {a = b;}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("newbarn.in","r",stdin);
    freopen("newbarn.out","w",stdout);

    memset(lift,-1,sizeof(lift));
    int q; cin >> q;
    int n = 0, c = 0;
    F0R(i,q) {
        char t; int a; cin >> t >> a;
        a--;
        if (t=='B') {
            if (a!=-2) { // update existing tree
                lift[0][n] = a;
                FOR(i,1,l2d) { // update bin lift arrays
                    if (lift[i-1][n]!=-1) {lift[i][n] = lift[i-1][lift[i-1][n]];}
                }
                depth[n] = depth[a]+1;
                comp[n] = comp[a];

                cmp(diam[comp[n]],{diam[comp[n]].f,n}); // update diameter of tree
                cmp(diam[comp[n]],{diam[comp[n]].s,n});
            } else { // make new tree
                diam[n] = {n,n};
                depth[n] = 0;
                comp[n] = c++;
            }

            n++;
        } else {
            cout << max(dist(diam[comp[a]].f,a),dist(diam[comp[a]].s,a)) << '\n'; // max dist to endpoint of diameter
        }
    }
}