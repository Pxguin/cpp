#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 1e6+1;
ll hsh[MAX_N], h[MAX_N];
int sz[MAX_N], par[MAX_N];
int p[MAX_N], q[MAX_N];
unordered_map<ll,int> paired; // stores value of R -> sum of all sz_j with R_j=R
ll pairs = 0, notgood = 0;

int get(int x) {return (par[x]==x ? x : par[x]=get(par[x]));}
void upd_pair(int a, int m) {
    if (hsh[a]) { // count # indices whose components have the negative hash
        pairs += (ll)m*sz[a]*paired[-hsh[a]]; // calc number of pairs
        paired[hsh[a]] += m*sz[a]; // update array
        notgood += m; // update amount of not good components
    }
}
void unite(int x, int y) {
    int a = get(x), b = get(y);
    if (a==b) {return;}

    upd_pair(a,-1); upd_pair(b,-1); // delete the old components

    if (sz[a]<sz[b]) {swap(a,b);}
    par[b] = a; sz[a] += sz[b]; hsh[a] += hsh[b];

    upd_pair(a,1); // reupdate for new one
}

void swp(int x, int y) {
    int a = get(x), b = get(y);
    
    if (a!=b) {
        upd_pair(a,-1); upd_pair(b,-1); // delete for old components
        hsh[a] += h[p[y]]-h[p[x]]; // update hashes
        hsh[b] += h[p[x]]-h[p[y]];

        upd_pair(a,1); upd_pair(b,1); // reupdate for new components
    }

    swap(p[x],p[y]);
}

void pre() {
    mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    F0R(i,MAX_N) {h[i] = uniform_int_distribution<ll>(0,1e12)(gen);}

    F0R(i,MAX_N) {
        par[i] = i;
        sz[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    pre();
    int n, nq; cin >> n >> nq;
    F0R(i,n) {
        cin >> p[i];
        q[i] = p[i];
    }
    sort(q,q+n);

    F0R(i,n) { // initial hash & setup
        hsh[i] = h[p[i]]-h[q[i]];
    }
    F0R(i,n) {upd_pair(i,1);}

    F0R(i,nq) {
        int t; cin >> t;
        if (t==1) {
            int a, b; cin >> a >> b;
            swp(--a,--b);
        } else if (t==2) {
            int a, b; cin >> a >> b;
            unite(--a,--b);
        } else if (t==3) {
            cout << (notgood ? "NE" : "DA") << '\n';
        } else {
            cout << pairs << '\n';
        }
    }
}