#include <iostream>

using namespace std;

int main() {
    pair<int,int> mods[7] = {{0,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
    freopen("div7.in","r",stdin);freopen("div7.out","w",stdout);
    int n; cin >> n;int m;long long sum = 0;int max = 0;
    for (int i=0;i<n;i++) {
        cin >> m; sum += m;
        if (mods[sum%7].first == -1) {mods[sum%7].first = i+1;} else {mods[sum%7].second = i+1;}
    }
    for (int i = 0; i < 7; i++) {
        if ((mods[i].second - mods[i].first) > max) {max = mods[i].second-mods[i].first;}
    }
    cout << max;
    fclose(stdin);fclose(stdout);
}