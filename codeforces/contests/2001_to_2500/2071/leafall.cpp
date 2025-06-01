#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const ll mod = 998244353;
ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {ll c = (a+b)%mod; if (c<0) {c+=mod;} return c;}
void add2(ll& a, ll b) {a = add(a,b);}
void mul2(ll& a, ll b) {a = mul(a,b);}
ll inv(ll a) {
    ll res = 1, b = mod-2;
    while (b) {
        if (b&1) {res = mul(a,res);}
        a = mul(a,a); b /= 2;
    } return res;
}

void solve() {
    int n; cin >> n;
    vec<ll> p(n), q(n), prob(n), invprob(n), notfall(n);
    vec<vec<int>> adj(n);
    for (int i=0;i<n;i++) {
        cin >> p[i] >> q[i];
        prob[i] = mul(p[i],inv(q[i])); // p/q 
        invprob[i] = mul(q[i]-p[i],inv(p[i])); // (q-p)/p ; so that prob[i]*invprob[i] = 1-prob[i]
        notfall[i] = add(1,-prob[i]); // (1-p)/q
    }
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    vec<ll> sum(n,1), sum2(n,0), totprob(n,0);
    vec<ll> dist1(n,0), dist2(n,0);
    ll tot = 0;
    for (int i=0;i<n;i++) { // probability that i becomes a leaf
        for (int x : adj[i]) {
            mul2(sum[i],prob[x]);
            add2(sum2[i],invprob[x]);
        }
        totprob[i] = mul(mul(sum[i],sum2[i]),notfall[i]);
        add2(tot,totprob[i]); // sum of all probabilities (for complementary counting)
    }
    for (int i=0;i<n;i++) { // sum of neighbours' probabilities
        for (int x : adj[i]) {add2(dist1[i],totprob[x]);}
    }
    ll ans = 0;
    for (int i=0;i<n;i++) { // nodes that are >2 edges away
        ll sub = totprob[i];
        for (int x : adj[i]) { // subtract probabilities of all nodes <=2 edges away
            add2(sub,add(add(dist1[x],-totprob[i]),totprob[x]));
        } add2(ans,mul(add(tot,-sub),totprob[i]));
    }

    for (int i=0;i<n;i++) { // nodes 2 edges away
        dist1[i] = 0;
        for (int x : adj[i]) { // consider the two cases: either i falls or i doesn't
            add2(dist1[i],mul(mul(sum[x],add(sum2[x],-invprob[i])),notfall[x])); // prob that i falls
            add2(dist2[i],mul(mul(sum[x],invprob[i]),notfall[x])); // prob that i stays
        }
    }
    for (int i=0;i<n;i++) {
        for (int x : adj[i]) {
            ll notx = mul(sum[i],inv(prob[x])); // prob that all neighbours fall (excluding x)
            ll fall = mul(mul(sum[i],add(sum2[i],-invprob[x])),notfall[i]);
            ll rest = mul(mul(notx,add(sum2[i],-invprob[x])),notfall[i]); // prob that i is a leaf (assuming x falls)
            add2(ans,mul(add(dist1[x],-fall),rest)); // prob that node x falls and i and another node adjacent to x become leaves

            ll stay = mul(mul(sum[i],invprob[x]),notfall[i]);
            add2(ans,mul(mul(add(dist2[x],-stay),notx),notfall[i])); // prob that only node x stays
        }
    }

    for (int i=0;i<n;i++) { // nodes 1 edge away
        for (int x : adj[i]) {
            add2(ans,mul(mul(sum[i],invprob[x]),mul(sum[x],invprob[i])));
        }
    }
    cout << mul(ans,inv(2)) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}