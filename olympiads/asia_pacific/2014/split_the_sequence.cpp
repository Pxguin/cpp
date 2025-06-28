#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define vec vector

const int MAX_N = 1e5+1, MAX_K = 201;
int a[MAX_N];
ll ss[MAX_N], ps[MAX_N];
int dp_prev[MAX_K][MAX_N];
vec<ll> dp(MAX_N), dp2(MAX_N);

double isect(pair<ll,ll> a, pair<ll,ll> b) {return (double)(a.s-b.s)/(b.f-a.f);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;

    for (int i=0;i<n;i++) {cin >> a[i+1];}
    ss[n+1] = ps[0] = 0;
    for (int i=n;i;i--) {ss[i] = ss[i+1]+a[i];}
    for (int i=1;i<=n;i++) {ps[i] = ps[i-1]+a[i];}

    fill(dp.begin(),dp.end(),0);
    deque<pair<pair<ll,ll>,int>> q;

    for (int i=1;i<=k;i++) {
        q.push_back({{-ps[i-1],dp[i-1]},i-1});

        for (int j=i;j<=n-1;j++) {
            while (q.size()>1 && isect(q.back().f,q.end()[-2].f)>=ss[j+1]) {q.pop_back();}
            dp2[j] = q.back().f.f*ss[j+1]+q.back().f.s+ps[j]*ss[j+1];
            dp_prev[i][j] = q.back().s;
            pair<pair<ll,ll>,int> line = {{-ps[j],dp[j]},j};
            while ((q.size() && q.front().f==line.f && q.front().s<=line.s) || (q.size()>1 && isect(line.f,q[1].f)>=isect(q[0].f,q[1].f))) {q.pop_front();}
            if (i!=1) {q.push_front(line);}
        }
        swap(dp,dp2); q.clear();
    }
    pair<ll,int> last = {0,0};
    for (int i=k;i<=n-1;i++) {chmax(last,make_pair(dp[i],i));}
    stack<int> ans;
    for (int i=k;i;i--) {
        ans.push(last.s);
        last.s = dp_prev[i][last.s];
    }
    cout << last.f << '\n';
    while (ans.size()) {
        cout << ans.top() << ' '; ans.pop();
    }
}