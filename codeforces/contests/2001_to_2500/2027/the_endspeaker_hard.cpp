#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll mod = 1e9+7;
pii cmp(pii a, pii b) {
    if (a.f<b.f) {return a;}
    else if (b.f<a.f) {return b;}
    else {return {a.f,(a.s+b.s)%mod};}
}

const int MAX_N = 3e5;
const pii MAX_PAIR = {LLONG_MAX,-1};
pii st[4*MAX_N];
int n, m;

void upd(int idx, pii val, int l=0, int r=n-1, int cur=1) {
    if (l==r) {
        st[cur] = val;
    } else {
        int m = (l+r)/2;
        if (idx<=m) {upd(idx,val,l,m,2*cur);}
        else {upd(idx,val,m+1,r,2*cur+1);}
        st[cur] = cmp(st[2*cur],st[2*cur+1]);
    }
}

pii mn(int l, int r, int tl=0, int tr=n-1, int cur = 1) {
    if (l > r) {return MAX_PAIR;}
    if (l==tl && r==tr) {return st[cur];}
    int tm = (tl+tr) / 2;
    return cmp(mn(l,min(r,tm),tl,tm,cur*2),mn(max(l,tm+1),r,tm+1,tr,cur*2+1));
}

void solve() {
    cin >> n >> m;
    v<int> a(n+1), b(m);
    F0R(i,n) {cin >> a[i];}
    F0R(i,m) {cin >> b[i];}

    v<v<pii>> dp(n+1,v<pii>(m+1,MAX_PAIR));
    dp[0][0] = {0,1};

    F0R(j,m) {
        fill(st,st+4*n,MAX_PAIR);
        int ptr = 0; ll sum = 0;
        F0R(i,n) {
            if (j) {dp[i][j] = cmp(dp[i][j],dp[i][j-1]);} // transition 1: increase k
            upd(i,dp[i][j]);

            sum += a[i];
            while (ptr<=i && sum>b[j]) {sum -= a[ptr++];} // [ptr,i] stores transitionable values

            dp[i+1][j] = mn(ptr,i); // find minimum in that range
            if (dp[i+1][j].f!=LLONG_MAX) {
                dp[i+1][j].f += m-j-1;
            }
        }
    }

    pii ans = MAX_PAIR;
    F0R(i,m) {ans = cmp(ans,dp[n][i]);}
    if (ans.f==LLONG_MAX) {cout << -1;}
    else {cout << ans.f << ' ' << ans.s;}
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}