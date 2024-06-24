#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    for (int z=0;z<t;z++) {
        unordered_set<long> non_zero;
        int n; cin >> n; long a;
        int jumps[n+1];
        vector<long> frogs;
        for (int i=0;i<n;i++) {
            jumps[i+1] = 0;
            cin >> a; if (a <= n) {frogs.push_back(a);}
        }
        sort(frogs.begin(),frogs.end());
 
        int ans = 0;
        auto p1 = frogs.begin();
        while (p1 != frogs.end()) {
            auto p2 = upper_bound(p1, frogs.end(), *p1);
            long ctr = p2-p1;
            for (int j=1;j<=n/(*p1);j++) {
                jumps[j*(*p1)] += ctr;
                non_zero.insert(j*(*p1));
            }
            p1 = p2;
        }
        for (auto i=non_zero.begin(); i!=non_zero.end(); i++) {
            ans = max(jumps[*i],ans);
        }

        cout << ans << "\n";
    }
}