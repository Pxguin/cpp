#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5;
int lef[N], rig[N], a[N];
ll ans[N], sum[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i];}
    memset(lef,-1,sizeof(lef)); memset(rig,-1,sizeof(rig));
    
    stack<int> st;
    int t = -1, last = -1;
    for (int i=0;i<n;i++) { // max cartesian tree
        while (st.size() && a[st.top()]<=a[i]) {
            last = st.top();
            st.pop();
        }
        if (st.size()) {rig[st.top()] = i;}
        if (t!=-1 && a[i]>=a[t]) {lef[i] = last;}
        st.push(i);
        t = last = i;
    }
    
    function<void(int)> dfs = [&](int cur) { // get subtree sums
        sum[cur] = a[cur];
        if (lef[cur]!=-1) {
            dfs(lef[cur]);
            sum[cur] += sum[lef[cur]];
        }
        if (rig[cur]!=-1) {
            dfs(rig[cur]);
            sum[cur] += sum[rig[cur]];
        }
        ans[cur] = sum[cur];
    };

    function<void(int)> dfs2 = [&](int cur) { // get answers
        if (lef[cur]!=-1) {
            if (ans[lef[cur]]>a[cur]) {ans[lef[cur]] = ans[cur];}
            dfs2(lef[cur]);
        }
        if (rig[cur]!=-1) {
            if (ans[rig[cur]]>a[cur]) {ans[rig[cur]] = ans[cur];}
            dfs2(rig[cur]);
        }
    };
    
    int rt = n-1;
    for (int i=n-1;i>=0;i--) { // find root of tree
        if (a[i]>a[rt]) {rt = i;}
    }
    dfs(rt);
    dfs2(rt);
    for (int i=0;i<n;i++) {
        if (i>0 && a[i-1]==a[i] && (i==n-1 || a[i+1]>=a[i])) {ans[i] = a[i];} // special case
        cout << ans[i] << ' ';
    }
}