#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define f first
#define s second
 
void solve() {
    int n; cin >> n;
    int a[n];
    int ans = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    } n--;
    while (--n >= 0) {
        if (a[n] > a[n+1]) {
            ans = max(ans,a[n]);
            a[n] = 0;
        }
    }
    cout << ans << "\n";
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t; 
	while (t--) {solve();}
}