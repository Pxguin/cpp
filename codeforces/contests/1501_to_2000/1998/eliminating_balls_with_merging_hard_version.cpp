#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()
#define vec vector

const int l2 = 17;
int log2_floor(unsigned long long i) {
    return __builtin_clzll(1) - __builtin_clzll(i);
}

void solve() {
    int n, asdf; cin >> n >> asdf;
    vec<int> a(n+1), l(n+1,n+1);
    vec<ll> ps(n+1);
    ps[0] = 0;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1]+a[i];
    }

    vec<vec<ll>> table(l2+1,vec<ll>(n));
    for (int i=0;i<n;i++) {table[0][i] = ps[i]-a[i+1];}
    for (int i=1;i<=l2;i++) {
        for (int j=0;j<=n-(1<<i);j++) {
            table[i][j] = min(table[i-1][j],table[i-1][j+(1<<(i-1))]);
        }
    }
    auto mn_qry = [&](int l, int r) {
        int i = log2_floor(r-l+1);
        return min(table[i][l],table[i][r-(1<<i)+1]);
    };

    vec<int> add(n+2,0);
    stack<int> st;
    for (int i=1;i<=n;i++) {
        while (st.size() && a[st.top()]<=a[i]) {st.pop();}
        if (st.size()) {
            int mx = st.top();
            int r = max(i,(int)(lower_bound(all(ps),ps[mx]+a[mx])-ps.begin())); // ps[r]-ps[mx]>=a[mx] -> ps[r]>=ps[mx]+a[mx]
            if (r!=n+1) { // i<=j<=r-1 : ps[j]-ps[mx]>=a[j+1] -> min(ps[j]-a[j+1])>=ps[mx]
                if (r==i || mn_qry(i,r-1)>=ps[mx]) {
                    l[i] = max(r,l[mx]);
                }
            }
        } else {
            l[i] = i;
        }
        add[l[i]]++;
        st.push(i);
    }

    int ans = 0;
    for (int i=1;i<=n;i++) {
        if (a[i]>ps[i-1]) {ans = 0;}
        ans += add[i];
        cout << ans << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}