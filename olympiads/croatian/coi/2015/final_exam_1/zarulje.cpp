#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define v vector

ll mod = 1e9+7; // all for calculating mod inverses and binomial coefficients
ll mul(ll a, ll b) {return a*b%mod;}
void mul2(ll& a, ll b) {a = mul(a,b);}
ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) {res = mul(res,a);}
        a = mul(a,a);
        b /= 2;
    } return res;
}

const int MAX_N = 2e5;
int a[MAX_N], small_l[MAX_N+1], small_r[MAX_N+1], last[MAX_N], join[MAX_N];
v<int> comp[MAX_N];
ll ans[MAX_N+1];
ll fac[MAX_N+1], inv[MAX_N+1];

void calc() {
	fac[0] = 1;
	for (int i=1;i<MAX_N+1;i++) {fac[i] = mul(fac[i-1],i);}
	inv[MAX_N] = exp(fac[MAX_N],mod-2);
	for (int i=MAX_N;i;i--) {inv[i-1] = mul(inv[i],i);}
}

ll C(int n, int k) {
	return mul(fac[n],mul(inv[k],inv[n-k]));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    calc();
    int n, k; cin >> n >> k;

    stack<int> s, s2;
    for (int i=0;i<n;i++) {
        cin >> a[i]; a[i]--;
    }
    for (int i=0;i<n;i++) { // nearest smaller values on left and right
        while (s.size() && a[s.top()]>=a[i]) {s.pop();}
        small_l[i] = (s.empty() ? -1 : s.top());
        while (s2.size() && a[s2.top()]>=a[n-i-1]) {s2.pop();}
        small_r[n-i-1] = (s2.empty() ? n : s2.top());
        s.push(i); s2.push(n-i-1);

        last[a[i]] = n; // setup later variables
        ans[i] = 1;
        join[i] = -1;
    }
    
    small_l[n] = n+1; small_r[n] = 0; // base case

    for (int i=n-1;i>=0;i--) { // find components (check if this index belongs to the last component pertaining to this energy level)
        if (i<small_l[last[a[i]]]) { // if not, create a new component
            if (small_r[i]==small_l[last[a[i]]]) {
                join[last[a[i]]] = i; // side case: if turning off the initial lightbulb ends up joining two components together
            }
            last[a[i]] = i;
        }
        comp[last[a[i]]].pb(i);
    }

    for (int i=0;i<n;i++) {
        if (comp[i].empty()) {continue;}

        reverse(all(comp[i]));
        int m = comp[i].size();
        if (join[i]!=-1) { // side case: join two components together
            int tot = m+comp[join[i]].size();
            mul2(ans[small_l[i]],C(tot,m)); // ans is a multiplication/division 'difference' array
            mul2(ans[small_l[i]+1],exp(C(tot,m),mod-2)); // basically a range multiply operation
        }
        for (int j=0;j<m;j++) {
            mul2(ans[comp[i][j]],C(m-1,j)); // case where we turn off this lightbulb
            mul2(ans[comp[i][j]+1],exp(C(m-1,j),mod-2));
            if (j && comp[i][j]-1 != comp[i][j-1]) { // case where we turn off a lightbulb between two elements in component
                mul2(ans[comp[i][j-1]+1],C(m,j));
                mul2(ans[comp[i][j]],exp(C(m,j),mod-2));
            }
        }
    }
    for (int i=0;i<n;i++) {
        mul2(ans[i+1],ans[i]); // process all range multiplies
    }
    while (k--) { // queries are already precalculated
        int p; cin >> p;
        cout << ans[p-1] << '\n';
    }
}