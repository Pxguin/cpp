#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int x, y; cin >> x >> y;
    int n; cin >> n;
    vec<vec<int>> to(n+1,vec<int>(2,-1));
    vec<array<ll,4>> rect(n+1);
    for (int i=0;i<n;i++) {
        cin >> rect[i][0] >> rect[i][1] >> rect[i][2] >> rect[i][3];
        if (rect[i][0]>rect[i][2]) {swap(rect[i][0],rect[i][2]);}
        if (rect[i][1]>rect[i][3]) {swap(rect[i][1],rect[i][3]);}
    }

    rect[n] = {-1,0,-1,1};
    sort(all(rect),[&](auto& a, auto& b) {return a[2]<b[2];});

    set<pair<int,int>> todo;
    for (int i=n;i;i--) { // transitions
        auto it = todo.lower_bound(mp(rect[i][1],-1));
        while (it!=todo.end() && it->f<=rect[i][3]) {
            int id = it->s, b = (rect[id][1]-1==it->f ? 0 : 1);
            to[id][b] = i;
            it = todo.erase(it);
        }

        todo.insert({rect[i][1]-1,i});
        todo.insert({rect[i][3]+1,i});
    }

    vec<vec<pii>> dp(n+1,vec<pii>(2,{1e9,1e9}));
    // base case
    for (int i=n;i>=0;i--) {
        if (i==0) {
            dp[0][0].f = x+y;
        } else if (rect[i][1]<=y && rect[i][2]<=x && y<=rect[i][3]) {
            dp[i][0].f = (x-rect[i][2])+(y-rect[i][1]);
            dp[i][1].f = (x-rect[i][2])+(rect[i][3]-y);
            break;
        }
    }

    for (ll i=n;i;i--) { // dp
        if (dp[i][0].f==1e9) {continue;}
        int a = to[i][0], b = to[i][1];
        int dx;
        if (a!=-1) {
            dx = rect[i][2]-rect[a][2] + dp[i][0].f;
            chmin(dp[a][0],mp(dx+(rect[i][1]-rect[a][1]),i));
            chmin(dp[a][1],mp(dx+(rect[a][3]-rect[i][1]+2),i));
        } else {
            dx = rect[i][2]+1 + dp[i][0].f;
            chmin(dp[0][0],mp(dx+abs(rect[i][1]-1),i));
        }
        if (b!=-1) {
            dx = rect[i][2]-rect[b][2] + dp[i][1].f;
            chmin(dp[b][0],mp(dx+(rect[i][3]-rect[b][1]+2),-i));
            chmin(dp[b][1],mp(dx+(rect[b][3]-rect[i][3]),-i));
        } else {
            dx = rect[i][2]+1 + dp[i][1].f;
            chmin(dp[0][0],mp(dx+abs(rect[i][3]+1),-i));
        }
        rect[i][3]++; rect[i][1]--;
    }
    cout << dp[0][0].f << '\n';
    vec<pii> ans;
    int cur = 0, b = 0;
    while (cur!=1e9) { // recover answer
        int nxt = dp[cur][b].s, nb = 0;
        if (nxt<0) {nxt *= -1; nb = 1;}

        if (nxt==1e9) {
            if (rect[cur][b*2+1]!=y) {ans.pb({0,y-rect[cur][b*2+1]});}
            if (rect[cur][2]+1!=x) {ans.pb({x-(rect[cur][2]+1),0});}
        } else {
            ans.pb({0,rect[nxt][nb*2+1]-rect[cur][b*2+1]});
            ans.pb({rect[nxt][2]-rect[cur][2],0});
        }
        cur = nxt; b = nb;
    }
    cout << ans.size() << '\n';
    for (auto[a,b] : ans) {cout << a << ' ' << b << '\n';}
}