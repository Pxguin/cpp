#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;
    vec<int> a(n), ps_less(n+1,0), ps_more(n+1,0);
    for (int i=0;i<n;i++) {cin >> a[i];}

    ll ans = (ll)n*(n+1)/2;
    for (int i=0;i<n;i++) {ans += 9LL*((n-i)/2);} 
    // ans = (10* # of even length subarrays) + (# of odd length subarrays) for overcounting issues
    
    for (int x=1;x<=10;x++) { // count number of subarrays without a median of x
        for (int i=0;i<n;i++) {
            ps_less[i+1] = ps_less[i];
            ps_more[i+1] = ps_more[i];
            if (a[i]<x) {ps_less[i+1]++;} // if ps_r-ps_{l-1} > 0, then there are >=((r-l+1)/2) numbers <x in [l,r] 
            else if (a[i]>x) {ps_more[i+1]++;} // same thing, but for numbers >x in [l,r]
            if (i%2==0) {ps_less[i+1]--; ps_more[i+1]--;}
        }

        ordered_set<pii> used_less[2], used_more[2];
        map<pii,int> both[2];

        ll sub = 0;
        for (int i=n;i>=0;i--) { // fix left endpoint of range
            sub += (used_less[i&1].size()-used_less[i&1].order_of_key({ps_less[i],-1})); // subtract number of subarrays with positive sum
            used_less[i&1].insert({ps_less[i],i});
            sub += (used_more[i&1].size()-used_more[i&1].order_of_key({ps_more[i],-1})); // subtract number of subarrays with positive sum
            used_more[i&1].insert({ps_more[i],i}); // add number of subarrays where (# <x) = (# >x) = (r-l+1)/2
            sub -= both[i&1][{ps_less[i],ps_more[i]}];
            both[i&1][{ps_less[i],ps_more[i]}]++;
        }

        ans -= sub;
    } cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}