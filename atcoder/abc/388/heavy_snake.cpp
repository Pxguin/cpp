#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int t[100], v[100];

    int n, d; cin >> n >> d;
    for (int i=0;i<n;i++) {cin >> t[i] >> v[i];}

    for (int i=1;i<=d;i++) {
        int ans = 0;
        for (int j=0;j<n;j++) {
            ans = max(ans,t[j]*(v[j]+i)); // weight of the snake (thickness t_j, length l_j+k)
        } cout << ans << '\n';
    }
}