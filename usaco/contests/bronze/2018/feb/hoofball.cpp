#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("hoofball.in","r",stdin);
    freopen("hoofball.out","w",stdout);
    int n; cin >> n;
    vector<int> cows(n);
    int x;
    for (int i=0;i<n;i++) {
        cin >> x;
        cows[i] = x;
    }
    vector<int> to(n,-1);
    vector<int> from(n, 0);
    sort(cows.begin(), cows.end());

    // calculate what goes to what

    for (int i=0;i<n;i++) {
        if ((i == n-1 || (cows[i]-cows[i-1] <= cows[i+1]-cows[i])) && i != 0) {
            from[i-1]++;
            to[i] = i-1;
        }
        if ((i == 0 || (cows[i]-cows[i-1] > cows[i+1]-cows[i])) && i != n-1) {
            from[i+1]++;
            to[i] = i+1;
        }
    }

    int ans = 0;
    int pairs = 0;

    for (int i=0;i<n;i++) {
        if (from[i] == 0) {ans++;}
    }
    for (int i=0;i<n;i++) {
        if (from[i] == 1 && i == to[to[i]] && from[to[i]] == 1) {
            pairs++;
        }
    }

    cout << ans+(pairs/2) << "\n";
}