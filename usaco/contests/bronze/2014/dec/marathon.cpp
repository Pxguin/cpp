#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc_saved_dist(pair<int,int> cp1, pair<int,int> cp2, pair<int,int> cp3) {
    int skip_dist = abs(cp3.second-cp1.second) + abs(cp3.first-cp1.first);
    int total_dist = (abs(cp3.second-cp2.second) + abs(cp2.second-cp1.second)) + (abs(cp3.first-cp2.first) + abs(cp2.first-cp1.first));
    return total_dist - skip_dist;
}

int main() {
    freopen("marathon.in", "r", stdin); freopen("marathon.out", "w", stdout);
    int n; cin >> n;
    int x, y;
    pair<int,int> checkpoints[n];
    pair<int,int> last;
    int total_dist = 0;
    int max_saved_dist = 0;
    cin >> x >> y; checkpoints[0] = make_pair(x,y); last = checkpoints[0];
    for (int i=1;i<n;i++) {
        cin >> x >> y;
        checkpoints[i] = make_pair(x, y);
        total_dist += abs(x-last.first) + abs(y-last.second);
        last = checkpoints[i];
    }
    for (int i=1;i<n-1;i++) {max_saved_dist = max(max_saved_dist, calc_saved_dist(checkpoints[i-1], checkpoints[i], checkpoints[i+1]));}

    total_dist -= max_saved_dist;

    cout << total_dist;
}