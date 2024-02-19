#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);

    int n; cin >> n;
    string city; string state;
    unordered_map<string, int> key;
    for (int i=0;i<n;i++) {
        cin >> city >> state;
        city = city.substr(0,2);
        if (city == state) {continue;}
        if (key.count(city+state)) {
            key[city+state]++;
        } else {key[city+state] = 1;}
    }
    int ans = 0;
    for (auto &it : key) {
        city = it.first.substr(0,2);
        state = it.first.substr(2,2);
        if (key.count(state+city)) {
            ans += key[state+city]*it.second;
        }
    }
    cout << ans/2 << "\n";
}