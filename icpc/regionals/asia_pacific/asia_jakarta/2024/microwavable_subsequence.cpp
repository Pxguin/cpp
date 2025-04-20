#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    ll ans = (ll)n*(m-1);
    v<int> last(m+1,-1), a(n);

    v<int> queries(n,-1);
    indexed_set<int> s;
    F0R(i,n) {
        cin >> a[i];
        if (last[a[i]]!=-1) {queries[last[a[i]]+1] = i-1;} // "adjacent" values, at indices (i,j)
        last[a[i]] = i;
    }
    for (int i=n-1;i>=0;i--) { // calc distinct values w/ indexed set
        if (queries[i]==-1) {continue;} // (fenwick tree is good too, especially bc no coordinate compression is needed)

        int c = queries[i];
        s.insert(c+1);
        ans -= (m-1)-(c-i+1-(int)s.order_of_key(c+1));
    } cout << ans << '\n';
}