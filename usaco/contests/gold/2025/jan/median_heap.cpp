#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 2e5, l2d = 18;
ll dp[MAX_N][3];
ll a[MAX_N], c[MAX_N];
int n;

ll ans[MAX_N];

int mode(int x, int y, int z) {
    if (x==y) {return x;}
    if (y==z) {return y;}
    if (x==z) {return z;}
    return 1;
}

ll targ = 1e10; // what is the target median
void calc(int i) {
    for (int z=0;z<l2d;z++) { // repeat log2(n) times
        fill(dp[i],dp[i]+3,LLONG_MAX);
        ll init[3] = {c[i],c[i],c[i]}; // base case for this node
        if (a[i]<targ) {init[0] = 0;}
        else if (a[i]==targ) {init[1] = 0;}
        else {init[2] = 0;}

        if (2*i+2<n) {
            for (int l=0;l<3;l++) { // fix dp state for left child subtree
                for (int r=0;r<3;r++) { // fix dp state for right child subtree
                    for (int cur=0;cur<3;cur++) { // dp state for current node
                        int res = mode(l,r,cur); // update dp state for this child subtree (mode of states)
                        chmin(dp[i][res],init[cur]+dp[2*i+1][l]+dp[2*i+2][r]);
                    }
                }
            }
        } else {for (int j=0;j<3;j++) {dp[i][j] = init[j];}} // base case: i has no children
        i = (i-1)/2;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i] >> c[i];}
    
    for (int i=n-1;i>=0;i--) {calc(i);}

    vec<pii> val, qry, upd;
    for (int i=0;i<n;i++) {val.pb({a[i],i});}
    int q; cin >> q;
    for (int i=0;i<q;i++) {
        int x; cin >> x;
        qry.pb({x,i});
    }
    sort(all(val)); sort(all(qry));

    while (qry.size()) { // process queries offline
        auto[x,i] = qry.back(); qry.pop_back();
        
        if (targ!=x) {
            targ = x;
            while (upd.size()) { // update dp values while they change
                auto[x1,i1] = upd.back(); upd.pop_back();
                calc(i1);
            }
        }

        targ = x;
        while (val.size() && val.back().f>=x) { // update dp values while they change
            auto[x1,i1] = val.back(); val.pop_back();
            calc(i1);
            if (x1==x) {upd.pb({x1,i1});}
        }

        ans[i] = dp[0][1]; // answer for this query
    }

    for (int i=0;i<q;i++) {cout << ans[i] << '\n';}
}