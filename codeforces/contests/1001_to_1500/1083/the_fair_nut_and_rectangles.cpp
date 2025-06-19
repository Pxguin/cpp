#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

double isect(pii a, pii b) {return (double)(b.s-a.s)/(a.f-b.f);} // intersection point of two lines

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<array<ll,3>> rect(n);
    for (int i=0;i<n;i++) {
        cin >> rect[i][0] >> rect[i][1] >> rect[i][2];
    } sort(all(rect));

    deque<pii> lines; // a line is stored as a pair (m,b) for y=mx+b
    vec<ll> dp(n);
    ll ans = 0;

    for (int i=0;i<n;i++) {
        auto[x,y,a] = rect[i];
        dp[i] = x*y-a;
        while (lines.size()>1 && isect(lines.end()[-2],lines.back())>=y) {lines.pop_back();} // get rid of useless lines on hull
        if (lines.size()) { // get best dp value for current
            chmax(dp[i],lines.back().f*y+lines.back().s+x*y-a);
        }
        chmax(ans,dp[i]);
        pii line = {-x,dp[i]};
        while (lines.size()>1 && isect(line,lines[1])>=isect(lines[0],lines[1])) {lines.pop_front();} // remove lines that are not on hull
        lines.push_front(line); // add this line to hull
    }
    cout << ans << '\n';
}