#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

double isect(pii a, pii b) {return (double)(a.s-b.s)/(b.f-a.f);}

// convex hull trick

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    deque<pii> hull;
    vec<pii> trees(n);
    for (int i=0;i<n;i++) {cin >> trees[i].f >> trees[i].s;}

    int ps = 0, sum = 0, dist = 0;
    for (int i=n-1;i>=0;i--) {sum += (dist+=trees[i].s)*trees[i].f;}

    int ans = sum;
    for (int i=0;i<n;i++) {
        auto[w,d] = trees[i];
        ps += w;
        
        sum -= dist*w;
        while (hull.size()>1 && isect(hull.back(),hull[hull.size()-2])>=dist) {hull.pop_back();}
        int dp = sum;
        if (hull.size()) {chmin(dp,hull.back().f*dist+hull.back().s-ps*dist);}
        chmin(ans,dp);
        pii line = {ps,sum};
        
        while (hull.size()>1 && isect(hull[0],line)>=isect(hull[0],hull[1])) {hull.pop_front();}
        hull.push_front(line);

        sum += ps*d;
        dist -= d;
    } cout << ans << '\n';
}