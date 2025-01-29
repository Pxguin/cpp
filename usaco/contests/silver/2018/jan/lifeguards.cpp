#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin); freopen("lifeguards.out", "w", stdout);
    int n; cin >> n;
    long start, end;
    vector<pair<long, pair<int, int>>> events;
    long alone_time[n];
    for (int i=0;i<n;i++) {
        alone_time[i] = 0;
        cin >> start >> end;
        events.push_back({start, {0, i}}); // time, event type, lifeguard number
        events.push_back({end, {1, i}}); // 0 for start, 1 for end
    }
    sort(events.begin(),events.end());

    // scan events
    int lifeguards = 0;
    long min_alone_time = 1000000000, total_time = 0, cover_time;
    set<int> working;

    for (int i=0;i<2*n;i++) {
        auto event = events[i];
        if (event.second.first == 0) {lifeguards++; working.insert(event.second.second);}
        else {lifeguards--; working.erase(event.second.second);}
        if (lifeguards > 0) {
            cover_time = events[i+1].first - event.first;
            total_time += cover_time;
            if (lifeguards == 1) {alone_time[*working.begin()] += cover_time;}
        }
    }

    for (int i=0;i<n;i++) {min_alone_time = min(min_alone_time, alone_time[i]);}
    cout << total_time - min_alone_time;

}