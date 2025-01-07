#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n; cin >> n;
    v<int> a(n), idx(n);
    F0R(i,n) {cin >> a[i]; idx[i] = i;}

    sort(all(idx),[&](int a1, int b1) {return a[a1]>a[b1];});
    int mx = a[idx[0]];

    // dsu setup
    v<int> sz(n,1), par(n), left(n);
    v<v<int>> freq(n,v<int>(2,0));
    F0R(i,n) {par[i] = left[i] = i;}
    F0R(i,n) {freq[i] = {0,a[i]==mx};} // 0: even position, 1: odd position
    int strong[2] = {0}, weak[2] = {0}; // 0: even size, 1: odd size
    int tot = 0;

    auto doit = [&](int x, int m) {
        strong[sz[x]&1] += m*freq[x][1];
        weak[sz[x]&1] += m*freq[x][0];
        tot += m*((sz[x]+1)/2);
    };
    auto get1 = [&](auto& get1, int x)->int {return (par[x]==x ? x : (par[x] = get1(get1,par[x])));};
    auto get = [&](int x) {return get1(get1,x);};
    auto merge = [&](int x, int y) {
        int a = get(x), b = get(y);
        if (a==b) {return;}
        
        int s = freq[a][1]+(sz[a]&1 ? freq[b][0] : freq[b][1]);
        int w = freq[a][0]+(sz[a]&1 ? freq[b][1] : freq[b][0]);

        // update global variables
        doit(a,-1); doit(b,-1);

        // merge
        if (sz[b]>sz[a]) {swap(a,b);}
        par[b] = a;
        freq[a] = {w,s};
        sz[a] += sz[b];
        chmin(left[a],left[b]);

        // reupdate global variables
        doit(a,1);
    };
    
    // iterate over min (add all copies of X, then iterate over X)
    int ans = 0;
    int p = 0;
    idx.pb(n); a.pb(0);
    F0R(i,n+1) {
        if (a[idx[i]]!=a[idx[p]]) {
            FOR(j,p,i) { // do merging
                int c = idx[j];
                if (c && a[c-1]>=a[c]) {merge(c-1,c);}
                if (c!=n-1 && a[c+1]>=a[c]) {merge(c,c+1);}
            }

            FOR(j,p,i) {
                int c = idx[j];
                
                // do some updates
                int comp = get(c), pos = (c-left[comp]+1)&1;
                if (pos==0) {continue;} // reconsider the check function
                
                int sub = 0;
                if (c&&a[c-1]==mx) {sub++;}
                if (c!=n-1&&a[c+1]==mx) {sub++;}
                
                // calculate answer
                if (strong[1]+strong[0]+weak[0]+weak[1]-sub) {
                    if (strong[1]||strong[0]||weak[0]) {chmax(ans,a[c]+mx+tot);}
                    else {chmax(ans,a[c]+mx+tot-1);}
                }
            } p = i; i--; //cout << tot << '\n';
        } else if (i!=n) {
            doit(idx[i],1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}