#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int N = 1.5e5, B = 1000, L = 19;
vec<int> adj[N];
int n;

const int mod = 998244353;
int add(ll a, ll b) {ll c = (a+b)%mod; if (c<0) {c+=mod;} return c;}
void add2(ll& a, ll b) {a = add(a,b%mod);}
int mul(ll a, ll b) {return a*b%mod;}
ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) {res = mul(res,a);}
        a = mul(a,a); b /= 2;
    } return res;
}
int sz[N], binlift[L][N], dep[N];
int timer = 1, tin[N], tout[N];
void dfs_size(int cur, int par=-1, int d=0) {
    sz[cur] = 1; dep[cur] = d;
    binlift[0][cur] = par;
    tin[cur] = timer++;

    for (int x : adj[cur]) {
        if (x!=par) {
            dfs_size(x,cur,d+1);
            sz[cur] += sz[x];
        }
    }
    tout[cur] = timer-1;
}

ll temp[N];
int is_par(int a, int b) {
    int res = -1;
    if (dep[a]<dep[b]) {
        int d = dep[b]-dep[a]-1;
        for (int bit=0;bit<L;bit++) {
            if ((1<<bit)&d) {b = binlift[bit][b];}
        }
        if (binlift[0][b]==a) {res = b;}
    } return res; 
}

struct BIT {
    ll sums[N+2] = {0};
    void add(int i, int j, int a) {
        for (;i<=N;i+=i&-i) {sums[i] += a;}
        for (++j;j<=N;j+=j&-j) {sums[j] -= a;}
    }
    int sum(int i) {
        ll res = 0;
        for (;i;i-=i&-i) {res += sums[i];}
        return (res%mod+mod)%mod;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q; cin >> n >> q;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    int inv = exp(n,mod-2);
    memset(binlift,-1,sizeof(binlift));
    dfs_size(0);
    for (int b=1;b<L;b++) {
        for (int i=0;i<n;i++) {
            if (binlift[b-1][i]!=-1) {binlift[b][i] = binlift[b-1][binlift[b-1][i]];}
        }
    }

    BIT bit;
    ll tot = 0;

    vec<pair<ll,ll>> qry;
    for (int l=0;l<q;l+=B) {
        qry.clear();
        int r = min(q,l+B)-l;
        for (int i=0;i<r;i++) {
            int t; cin >> t;
            if (t==1) {
                int u, v; cin >> u >> v; u--;
                v = mul(inv,v);
                temp[u] += v;
                qry.pb({u,v});
            } else {
                int u; cin >> u;
                ll ans = add(tot,bit.sum(tin[--u]));

                for (auto[x,v] : qry) {
                    int sz_x = n, p = is_par(x,u);
                    if (x!=u) {sz_x -= (p==-1 ? n-sz[x] : sz[p]);}
                    ans += v*sz_x;
                }
                cout << ans%mod << '\n';
            }
        }
        for (int i=0;i<n;i++) {
            temp[i] %= mod;
            
            if (temp[i]==0) {continue;}

            bit.add(tin[i],tin[i],mul(temp[i],n));
            bit.add(tin[i],tout[i],-mul(temp[i],sz[i]));
            add2(tot,mul(temp[i],sz[i]));

            for (int x : adj[i]) {
                if (x!=binlift[0][i]) {
                    bit.add(tin[x],tout[x],mul(temp[i],n-sz[x]));
                }
            } temp[i] = 0;
        }
        for (int i=0;i<N+2;i++) {bit.sums[i] %= mod; if (bit.sums[i]<0) {bit.sums[i] += mod;}}
    }
}