#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int solve() {
    string s; cin >> s;
    string t; cin >> t;

    unordered_set<char> used;
    vector<int> to(52, -1);
    vector<int> from(52, 0);
    int ans = 0;
    int n = s.size();
    int x; int y;
    for (int i=0;i<n;i++) {
        used.insert(t[i]);
        x = max(min(25, s[i]-'A'), s[i]-'a'+26);
        y = max(min(25, t[i]-'A'), t[i]-'a'+26);

        if (to[x] == -1 || to[x] == y) {
            if (to[x] == -1) {from[y]++;}
            to[x] = y;
        } else {return -1;}
    }
    if (s == t) {return 0;}
    if (used.size() == 52) {return -1;}
    vector<bool> vis(52, false);
    for (int i=0;i<52;i++) {
        if (to[i] != -1 && to[i] != i) {
            if (!vis[i]) {
                bool flag = false;
                int j = i;
                while (true) {
                    vis[j] = true;
                    if (from[to[j]] > 1) {break;}
                    j = to[j];
                    if (j == i) {
                        flag = true;
                        break;
                    }
                    if (j == -1 || vis[j]) {break;}
                }
                if (flag) {ans++;}
            }
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {cout << solve() << "\n";}
}