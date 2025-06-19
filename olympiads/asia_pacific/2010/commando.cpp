#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second

const int N = 1e6;
int ps[N+1];
ll dp[N];

double isect(pii a, pii b) {return (double)(a.s-b.s)/(b.f-a.f);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ps[0] = dp[0] = 0;
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;

    deque<pii> q;
    q.push_front({0,0});

    ll sum = 0, ans = 0;
    for (int i=0;i<n;i++) {
        ll x; cin >> x;
        sum += x;
        while (q.size()>1 && isect(q[0],q[1])<=sum) {q.pop_front();} // get max on hull
        ans = q.front().f*sum+q.front().s + c+b*sum+a*sum*sum; // add in the constants to get dp value

        pii line = {-2*a*sum,a*sum*sum-b*sum+ans}; // push dp value into convex hull
        while (q.size()>1 && isect(q.back(),q.end()[-2])>=isect(q.back(),line)) {q.pop_back();}
        q.push_back(line);
    } cout << ans << '\n';
}