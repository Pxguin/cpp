#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> stops = {{0,0}};
int n;

int find_max_c(int start) {
    long max_c = 0;
    int max_c_i = 0;
    for (int i=start+1;i<n+1;i++) {
        if (stops[i].second > max_c) {
            max_c = stops[i].second; max_c_i = i;
        }
    }
    return max_c_i;

}

int main() {
    freopen("reststops.in", "r", stdin); freopen("reststops.out", "w", stdout);
    long long l, rf, rb; cin >> l >> n >> rf >> rb;
    long long r_diff = rf-rb, tastiness = 0, time;
    long long x, c;
    //pair<int,int> stop;
    for (int i=0;i<n;i++) {
        cin >> x >> c;
        stops.push_back({x, c});
    }
    sort(stops.begin(), stops.end());
    int max_c_i = 0;
    int prev_max = 0;

    //cout << find_max_c(0);
    do {
        prev_max = max_c_i;
        max_c_i = find_max_c(max_c_i);
        time = r_diff * (stops[max_c_i].first - stops[prev_max].first);
        tastiness += time * stops[max_c_i].second;
    } while (max_c_i != n);

    cout << tastiness;

    
}
