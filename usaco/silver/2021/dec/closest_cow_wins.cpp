#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    //freopen("cow.in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int k, m, n; cin >> k >> m >> n;
    vector<pair<long,long>> events(k+m);
    vector<long> nj; // nhoj's cows
    long pos;
    for (int i=0;i<k;i++) {cin >> events[i].first >> events[i].second;} // the patches
    for (int i=k;i<k+m;i++) {cin >> pos;
        events[i].first = pos; events[i].second = -1;
        nj.push_back(pos);
    }
    // one vector for patches + cows; one vector specifically for nhoj's cows
    nj.push_back(LONG_MIN); nj.push_back(LONG_MAX); // endpoints
    events.push_back({LONG_MIN,-1}); events.push_back({LONG_MAX, -1});
    sort(events.begin(),events.end());
    sort(nj.begin(), nj.end());

    vector<long long> answers;
    int ctr = 0;

    for (int i=0;i<k+m+1;i++) {
        if (events[i].second == -1) { // if is nhoj's cow
            ctr++;
            int l = i+1;
            int r = lower_bound(events.begin()+i+1,events.end(),
                                make_pair(nj[ctr],long(-1))) - events.begin();
            // finding the left and right endpoints of the segment

            if (l == r) {continue;}

            long long w_sum = 0;
            long long total = 0;
            long long max_sum = 0;

            //long window_size = (events[r].first-events[l-1].first)/2;
            //long window_left = events[l].first;
            long window_right = events[l].first + (events[r].first-events[l-1].first)/2;

            long w = 1; // this is the pointer scanning across the patches

            // building the window, using the first patch of grass as the leftmost point
            // window is defined as [window_left, window_right)
            for (int j=l;j<=r;j++) {
                if (j == r) {w = r+1; break;}
                if (events[j].first < window_right) {w_sum += events[j].second;}
                else {w = j; break;}
            }
            max_sum = w_sum;
            total = w_sum;

            // moving the window
            for (int j=l+1;j<r;j++) {
                long change = events[j].first - events[j - 1].first;
                w_sum -= events[j - 1].second;
                window_right += change;
                for (int z = w; z <= r; z++) {
                    if (z == r) {w = r+1; break;}
                    if (events[z].first < window_right) {
                        w_sum += events[z].second;
                        total += events[z].second;
                    } else {
                        w = z;
                        break;
                    }
                }
                max_sum = max(max_sum, w_sum);
            }
            answers.push_back(max_sum);
            answers.push_back(total-max_sum);
        }
    }

    sort(answers.rbegin(), answers.rend());
    answers.resize(n);
    long long ans = 0;
    for (long long i : answers) {ans += i;}
    cout << ans << "\n";
}