#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 4e5, log2dist = 18;
int lift[MAX_N][log2dist];
int a[MAX_N];
ll ps[MAX_N+1], exp_2[log2dist];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, k; cin >> n >> k;
    F0R(i,n) {
        cin >> a[i]; a[i+n] = a[i];
        ps[i+1] = ps[i+1+n] = a[i]; 
    }
    F0R(i,2*n) {ps[i+1] += ps[i];}
    F0R(i,2*n) {
        lift[i][0] = upper_bound(ps,ps+2*n+1,ps[i]+k)-ps-1;
    }
    FOR(p,1,log2dist) { // calculate lift array
        F0R(i,2*n) {
            if (lift[i][p-1]!=-1) {
                lift[i][p] = lift[lift[i][p-1]][p-1];
            }
        }
    }
    
    exp_2[0] = 1;
    F0R(i,log2dist-1) {exp_2[i+1] = exp_2[i]*2;}

    int ans = n;
    v<pii> to[MAX_N];
    F0R(i,n) {to[i].pb({i+n,1});} // start at index i, target is i+n, current # of steps is 1
    F0R(i,2*n) { // do greedy strategy
        int ptr = 0;
        for (auto[g,s] : to[i]) {
            if (lift[i][0]>=g) {chmin(ans,s);} // stop when even one jump overshoots target
            else {
                while (ptr+1<log2dist && lift[i][ptr+1]!=-1 && lift[i][ptr+1]<g) {ptr++;}
                to[lift[i][ptr]].pb({g,s+exp_2[ptr]}); // find largest jump that doesn't overshoot target
            }
        }
    } cout << ans << '\n';
}