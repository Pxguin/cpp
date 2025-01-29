#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    freopen("painting.in", "r", stdin); freopen("painting.out", "w", stdout);
    vector<pair<pair<pair<long, int>, int>, pair<long, long>>> events;
    set<pair<long, long>> relevant;
    pair<pair<pair<long, int>, int>, pair<long, long>> event;
    
    int n; cin >> n;
    long x, y, x2, y2;

    for (int i=0;i<n;i++) {
        cin >> x >> y >> x2 >> y2;
        events.push_back({{{x,0},i},{y,y2}}); // x pos, event type, id, y range of rect
        events.push_back({{{x2,1},i},{y,y2}}); // 0 = start, 1 = end
    }
    sort(events.begin(),events.end());

    int ans = 0;
    bool visited[n];
    set<pair<long,long>>::iterator index;

    for (int i=0;i<2*n;i++) {
        event = events[i];
        x = event.first.first.first;
        y = event.second.first;
        y2 = event.second.second;

        if (event.first.first.second == 0) { // event type
            index = (relevant.upper_bound({y,y}));
            if ((index == relevant.begin()) || ((*prev(index, 1)).second < y)) {
                visited[event.first.second] = true;
                relevant.insert({y,y2});
                ans++;
            }
        }
        else if (visited[event.first.second]) {
            relevant.erase({y,y2});
        }
    }

    cout << ans;
}