#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll l, r, n; cin >> l >> r >> n;
    v<pair<char,string>> op(n+27);
    op[0] = {'a',"a"};
    F0R(i,n) {
        cin >> op[i+1].f >> op[i+1].s;
    }
    n += 27;
    FOR(i,n-26,n) {op[i] = {'a'+i-(n-26),to_string('a'+i-(n-26))};}

    v<ll> len(26), tsz(n,0);
    v<v<ll>> idx(n), sz(n);
    iota(all(len),n-26);
    FOR(i,n-26,n) {tsz[i]=1;}
    FOR(i,n-26,n) {idx[i].pb(i);}

    for (int i=n-27;i>=0;i--) { // calc subtree sizes and children, and compress paths
        sz[i].pb(0);
        for (char c : op[i].s) {
            int nxt = len[c-'a'];
            if (idx[nxt].size()==1) {nxt = idx[nxt][0];} // this is the compression
            idx[i].pb(nxt);
            tsz[i] = min((ll)1e18+1,tsz[i]+tsz[nxt]);
            sz[i].pb(tsz[i]);
        } len[op[i].f-'a'] = i;
    }

    v<int> comps;
    auto dfs = [&](auto& dfs, int cur, ll lp, ll rp)->void { // dfs to find all segments
        if (lp>r || rp<l) {return;}
        int left = (lp<l ? lower_bound(all(sz[cur]),l-lp)-sz[cur].begin() : 0);
        int right = (rp>r ? lower_bound(all(sz[cur]),r-lp+2)-sz[cur].begin() : sz[cur].size());

        if (left==0 && right==sz[cur].size()) {comps.pb(cur);}
        else {
            if (left!=0) { // left child
                dfs(dfs,idx[cur][left-1],min((ll)1e18+1,sz[cur][left-1]+lp),min((ll)1e18+1,sz[cur][left]+lp-1));
            }
            FOR(j,left+1,right) {comps.pb(idx[cur][j-1]);} // middle children
            if (left!=right && right!=sz[cur].size()) { // right child
                dfs(dfs,idx[cur][right-1],min((ll)1e18+1,sz[cur][right-1]+lp),min((ll)1e18+1,sz[cur][right]+lp-1));
            }
        }
    }; dfs(dfs,0,1,tsz[0]);

    string ans = "";
    auto getsubtree = [&](auto& getsubtree, int cur)->void {
        if (cur>n-27) {ans += (char)'a'+cur-(n-26);}
        else {
            for (int i : idx[cur]) {getsubtree(getsubtree,i);}
        }
    };
    for (int i : comps) {getsubtree(getsubtree,i);}

    /*v<string> subtree(n,"");
    FOR(i,n-26,n) {subtree[i] = ('a'+i-(n-26));}
    auto getsubtree = [&](auto& getsubtree, int cur)->void { // alternative: memoize solution
        for (int i : idx[cur]) {
            if (subtree[i]=="") {getsubtree(getsubtree,i);}
            subtree[cur] += subtree[i];
        }
    };
    for (int i : comps) {
        if (subtree[i]=="") {getsubtree(getsubtree,i);}
        ans += subtree[i];
    }*/
    
    cout << ans << '\n';
}