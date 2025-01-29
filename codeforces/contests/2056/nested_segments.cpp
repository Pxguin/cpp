#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 3e5;
ll catalan[MAX_N+1], fac[2*MAX_N+1], inv[2*MAX_N+1];
ll mod = 998244353;
ll mul(ll a, ll b) {return a*b%mod;}

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b%2) {res = mul(res,a);}
        a = mul(a,a);
        b /= 2;
    } return res;
}

void calc() {
    fac[0] = 1;
    F0R(i,2*MAX_N) {fac[i+1] = mul(i+1,fac[i]);}
    inv[2*MAX_N] = exp(fac[2*MAX_N],mod-2);
    for (int i=2*MAX_N;i;i--) {inv[i-1] = mul(inv[i],i);}
    for (int i=0;i<=MAX_N;i++) {catalan[i] = mul(fac[2*i],mul(inv[i],inv[i+1]));}
}

void solve() {
    int n, m; cin >> n >> m;
    v<pii> pts, seg(m);
    int rt = m;
    F0R(i,m) {
        int l, r; cin >> l >> r;
        pts.pb({l,i}); pts.pb({-r,i});
        seg[i] = {l,r};
        if (l==1 && r==n) {rt = i;}
    } 
    if (rt==m) { // make segment [1,n] if it doesn't exist
        seg.pb({1,n}); pts.pb({1,m}); pts.pb({-n,m});
        m++;
    }
    
    sort(all(pts),[&](pii a, pii b) { // sort segments in tree 
        if (a.f==b.f) {
            if (a.f>0) {return seg[a.s].s>seg[b.s].s;}
            return seg[a.s].f>seg[b.s].f;
        } 
        if (a.f==-b.f) {return a.f>0;}
        return abs(a.f)<abs(b.f);
    });

    stack<int> st;
    v<v<int>> adj(m);
    for (pii x : pts) { // actually construct tree (with stack)
        if (x.f>0) {
            if (st.size()) {adj[st.top()].pb(x.s);}
            st.push(x.s);
        } else {
            st.pop();
        }
    }
    v<ll> ans(m,1);
    auto dfs = [&](auto& dfs, int cur)->void { // implicit tree is probably possible, but dfs works too
        ll len = seg[cur].s-seg[cur].f;
        for (int x : adj[cur]) {
            dfs(dfs,x);
            ans[cur] = mul(ans[cur],ans[x]);
            len -= seg[x].s-seg[x].f;
        }
        ans[cur] = mul(ans[cur],catalan[len]);
    };
    dfs(dfs,rt);
    cout << ans[rt] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    calc();

    int t; cin >> t;
    while (t--) {solve();}
}