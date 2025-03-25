#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vec<ordered_set<int>> nums(1);
int sz = 0;
ll ans = 0;

void dfs(int idx) {
    int a; cin >> a;
    if (a==0) { // dfs left and right
        nums.pb(ordered_set<int>());
        nums.pb(ordered_set<int>());
        int l = ++sz, r = ++sz;
        dfs(l); dfs(r);

        if (nums[l].size()>nums[r].size()) {nums[l].swap(nums[r]);}
        ll cand = 0, cand2 = 0;
        for (int x : nums[l]) { // get # inversions
            int y = nums[r].order_of_key(x);
            cand += y;
            cand2 += nums[r].size()-y;
        }
        for (int x : nums[l]) {nums[r].insert(x);} // merge small to large
        nums[l].clear();
        nums[r].swap(nums[idx]);
        ans += min(cand,cand2);
    } else { // leaf
        nums[idx].insert(a);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    dfs(0);
    cout << ans << '\n';
}