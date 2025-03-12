#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

const int l2d = 19;

void solve() {
    int n; cin >> n;

    vec<int> dep(n+2,0), sum(n+2,0);
    vec<vec<int>> lift(l2d,vec<int>(n+2,-1));
    vec<vec<int>> mn(l2d,vec<int>(n+2,0));
    vec<vec<int>> mx(l2d,vec<int>(n+2,0));
    vec<vec<int>> mxmn(l2d,vec<int>(n+2,0));
    vec<vec<int>> mnmx(l2d,vec<int>(n+2,0));

    mn[0][1] = mx[0][1] = mxmn[0][1] = sum[1] = dep[1] = 1; // base cases for node 1
    lift[0][1] = 0;

    auto get_max = [&](int a, int d) { // get maximum prefix sum on the path between a and its dth ancestor
        int res = INT_MIN;
        for (int i=0;i<l2d;i++) {
            if ((1<<i)&d) {
                res = max(res,mx[i][a]);
                a = lift[i][a];
            }
        } return max(res,mx[0][a]);
    };
    auto get_min = [&](int a, int d) { // get minimum prefix sum on a path
        int res = INT_MAX;
        for (int i=0;i<l2d;i++) {
            if ((1<<i)&d) {
                res = min(res,mn[i][a]);
                a = lift[i][a];
            }
        } return min(res,mn[0][a]);
    };
    auto jump = [&](int a, int d) { // get kth ancestor
        for (int i=0;i<l2d;i++) {
            if ((1<<i)&d) {a = lift[i][a];}
        } return a;
    };
    auto get_mxmn = [&](int a, int d) { // get maximum subsegment sum on a path
        int i = log2(d+1);
        int res = max(mxmn[i][a],mxmn[i][jump(a,d-(1<<i)+1)]); // do sparse table
        chmax(res,mx[i][a]-get_min(lift[i][a],d-(1<<i)+1)); // consider the case not considered by sparse table
        return res;
    };
    auto get_mnmx = [&](int a, int d) { // get minimum subsegment sum on a path
        int i = log2(d+1);
        int res = min(mnmx[i][a],mnmx[i][jump(a,d-(1<<i)+1)]);
        chmin(res,mn[i][a]-get_max(lift[i][a],d-(1<<i)+1));
        return res;
    };
    auto lca = [&](int a, int b) {
        a = jump(a,dep[a]-dep[b]);
        if (a==b) {return a;}
        for (int i=l2d-1;i>=0;i--) {
            if (lift[i][a]!=lift[i][b]) {
                a = lift[i][a];
                b = lift[i][b];
            }
        }
        return lift[0][a];
    };

    int c = 2;
    while (n--) {
        char t; cin >> t;
        if (t=='+') {
            int a, b; cin >> a >> b;
            dep[c] = dep[a]+1; // base cases for lift arrays
            sum[c] = sum[a]+b; // sum is prefix sum from root to this node
            mx[0][c] = sum[c]; // max prefix sum in lift
            mn[0][c] = sum[c]; // min prefix sum in lift

            lift[0][c] = a;
            chmax(mxmn[0][c],b); // max subsegment sum in lift
            chmin(mnmx[0][c],b); // min subsegment sum in lift

            for (int i=1;i<l2d;i++) { // update all lift arrays
                if (lift[i-1][c]!=-1 && lift[i-1][lift[i-1][c]]!=-1) {
                    lift[i][c] = lift[i-1][lift[i-1][c]];
                    mx[i][c] = max(mx[i-1][c],mx[i-1][lift[i-1][c]]); // basic lifts
                    mn[i][c] = min(mn[i-1][c],mn[i-1][lift[i-1][c]]);
                    mxmn[i][c] = max(max(mxmn[i-1][c],mxmn[i-1][lift[i-1][c]]),mx[i-1][c]-min(mn[i-1][lift[i-1][c]],mn[0][lift[i][c]]));
                    mnmx[i][c] = min(min(mnmx[i-1][c],mnmx[i-1][lift[i-1][c]]),mn[i-1][c]-max(mx[i-1][lift[i-1][c]],mx[0][lift[i][c]]));
                    // for subsegment lifts, do: 1) traditional lifts  2) create a new subsegment (starts in first half of lift, ends in second half of lift)
                }
            }
            c++;

        } else {
            int a, b, k; cin >> a >> b >> k;
            if (dep[a]<dep[b]) {swap(a,b);}
            int l = lca(a,b), d = dep[a]-dep[l], d2 = dep[b]-dep[l];

            int lo = get_mnmx(a,d), hi = get_mxmn(a,d);
            if (l!=b) { // consider the case where the path wraps around the LCA
                chmin(lo,get_mnmx(b,d2));
                chmax(hi,get_mxmn(b,d2));
                chmin(lo,get_min(a,d)+get_min(b,d2)-sum[l]-sum[lift[0][l]]); // maxps(root to a) + maxps(root to b) - 2*ps(root to lca) + val[lca]
                chmax(hi,get_max(a,d)+get_max(b,d2)-sum[l]-sum[lift[0][l]]);
            }
            cout << (lo<=k && k<=hi ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}