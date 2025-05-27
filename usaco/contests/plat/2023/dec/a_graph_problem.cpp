#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int MAX_N = 2e5;
int n;
int par[MAX_N];
vec<int> comp[MAX_N];
ll ans[MAX_N] = {0}, delta[MAX_N] = {0};

ll inv[MAX_N+1], ex[MAX_N+1];
const ll INV = 700000005, mod = 1e9+7;

ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {ll c = (a+b)%mod; if (c<0) {c += mod;} return c;}

int get(int x) {return par[x]==x ? x : par[x]=get(par[x]);}
void merge(int x, int y, ll z) {
    int a = get(x), b = get(y);
    if (a==b) {return;}
    if (comp[a].size()<comp[b].size()) {swap(a,b); swap(x,y);}

    ll add_a = mul(add(delta[b],ans[y]),inv[comp[a].size()]); // add_a: how much is needed to add to all vertices in set a
    ll add_b = mul(add(delta[a],ans[x]),inv[comp[b].size()]); // add_b: amt needed to add to all vertices in set b
    add_a = add(add_a,delta[a]);
    add_a = add(add_a,mul(z,ex[n-comp[a].size()-1]));
    add_b = add(add_b,delta[b]);
    add_b = add(add_b,mul(z,ex[n-comp[b].size()-1]));

    ll sub = add(add_b,-add_a);
    for (int i : comp[b]) { // merge sets and stuff
        ans[i] = add(ans[i],sub);
        comp[a].pb(i);
    }
    par[b] = a;
    delta[a] = add_a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    inv[0] = 1; ex[0] = 1;
    for (int i=1;i<=MAX_N;i++) {inv[i] = mul(inv[i-1],INV);}
    for (int i=1;i<=MAX_N;i++) {ex[i] = mul(ex[i-1],10);}

    int m; cin >> n >> m;

    for (int i=0;i<n;i++) {
        par[i] = i;
        comp[i] = {i};
    }
    
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        merge(--a,--b,i+1);
    }
    for (int i=0;i<n;i++) {
        cout << add(ans[i],delta[get(i)]) << '\n';
    }
}