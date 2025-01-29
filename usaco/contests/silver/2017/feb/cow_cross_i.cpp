#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int c, n; cin >> c >> n;
    vector<int> chicken(c);
    vector<pair<int,int>> cows(n);
    for (int& i : chicken) {cin >> i;}
    for (pair<int,int>&i : cows) {cin >> i.second >> i.first;}
    sort(cows.begin(), cows.end());
    sort(chicken.begin(), chicken.end());

    bool flag = false;
    int ans = 0;
    vector<bool> vis(n,false);
    for (int i=0;i<c;i++) {
        auto it = lower_bound(cows.begin(), cows.end(), make_pair(chicken[i],-1));
        if (it == cows.end()) {flag = true; break;}
        while ((*it).second > chicken[i] || vis[it-cows.begin()]) {
            it++;
            if (it == cows.end()) {flag = true; break;}
        }
        if (!flag) {
            ans++;
            vis[it-cows.begin()] = true;
        } else {flag = false;}
    }
    cout << ans << "\n";
}