#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

double isect(pii a, pii b) {return (double)(a.s-b.s)/(b.f-a.f);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int k, n; cin >> n >> k;
    vec<ll> c(n+1,0);
    vec<ll> ps(n+1,0), sum(n+1,0);
    ll tot = 0;
    for (int i=0;i<n;i++) {cin >> c[i+1];}
    for (int i=1;i<=n;i++) {
        ps[i] = c[i]; sum[i] = i*c[i];
        ps[i] += ps[i-1]; sum[i] += sum[i-1];
    }
    vec<ll> dp1(n+1,1e17);
    dp1[0] = 0;

    for (int i=1;i<=k;i++) { // how many houses placed down
        vec<ll> dp2(n+1,LLONG_MAX);
        deque<pii> q;
        q.push_back({-ps[i-1],sum[i-1]+dp1[i-1]});
        for (ll j=i;j<=n;j++) { // fix left side of range
            while (q.size()>1 && isect(q[0],q[1])<=j) {q.pop_front();}
            dp2[j] = q.front().f*j+q.front().s + ps[j]*j-sum[j];
            pii line = {-ps[j],sum[j]+dp1[j]};
            while (q.size()>1 && isect(q.back(),line)<=isect(q.back(),q.end()[-2])) {q.pop_back();}
            q.push_back(line);
        }
        q.clear();

        for (ll j=i;j<=n;j++) { // fix right side of range
            dp1[j] = dp2[j];
            while (q.size()>1 && isect(q[0],q[1])<=ps[j]) {q.pop_front();}
            if (q.size()) {chmin(dp1[j],q.front().f*ps[j]+q.front().s+sum[j]);}
            
            pii line = {-j,dp2[j]+ps[j]*j-sum[j]};
            while (q.size()>1 && isect(q.back(),line)<=isect(q.back(),q.end()[-2])) {q.pop_back();}
            q.push_back(line);
        }
    }
    cout << dp1[n] << '\n';
}