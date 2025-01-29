#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("fpot.in","r",stdin);freopen("fpot.out","w",stdout);
    int n, d; cin >> n >> d;
    int x, y;
    vector<pair<int,int>> rain;
    for (int i=0;i<n;i++) {
        cin >> x >> y;
        rain.push_back(make_pair(x,y));
    }
    sort(rain.begin(),rain.end());
    int p1 = 0; int p2 = p1;
    multiset<int> relevant; relevant.insert(rain[0].second);
    // multiset to store lowest and highest y values in current range
    int ans = INT_MAX;

    while (p1 <= p2 && p2 < n) {
        if ((*--relevant.end())-(*relevant.begin()) >= d) {
            ans = min(ans, rain[p2].first-rain[p1].first);
            // rain[p2].first-rain[p1].first = width
            p1++;
            relevant.erase(relevant.lower_bound(rain[p1-1].second));
        } else {
            p2++;
            relevant.insert(rain[p2].second);
        }
    }
    if (ans == INT_MAX) {cout << -1;}
    else {cout << ans;}
}