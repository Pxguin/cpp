#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)

const int N = 2000, K = 7;
int r[N];
ll ss[N], dp[K][N];

double isect(pii a, pii b) {return (double)(b.s-a.s)/(a.f-b.f);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);

    int n, k; cin >> n >> k;
    for (int i=0;i<n;i++) {cin >> r[i]; r[i+n] = r[i];}
    ll ans = LLONG_MAX;

    for (int start=0;start<n;start++) {
        for (int i=start;i<start+n;i++) {
            dp[0][i] = LLONG_MAX;
        }

        ss[start+n-1] = r[start+n-1];
        dp[0][start] = 0;
        for (int i=start+n-2;i>=start;i--) {
            dp[0][start] += ss[i+1];
            ss[i] = ss[i+1]+r[i];
        }

        for (int i=1;i<k;i++) {
            deque<pii> q;
            for (int j=start;j<start+n;j++) {
                while (q.size()>1 && isect(q.back(),q.end()[-2])>=ss[j]) {q.pop_back();}
                dp[i][j] = (q.size() ? q.back().f*ss[j]+q.back().s-ss[j]*j : LLONG_MAX);
                if (dp[i-1][j]!=LLONG_MAX) {
                    pii line = {j,dp[i-1][j]};
                    while (q.size()>1 && isect(line,q[0])>=isect(q[0],q[1])) {q.pop_front();}
                    q.push_front(line);
                }
            }
        }
        for (int i=start;i<start+n;i++) {chmin(ans,dp[k-1][i]);}
    } cout << ans << '\n';
}