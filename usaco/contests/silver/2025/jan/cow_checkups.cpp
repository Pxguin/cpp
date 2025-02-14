#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n), b(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n;i++) {cin >> b[i];}

    ll ans = 0;
    auto solve = [&]() {
        v<v<int>> a2(n), b2(n);
        for (int i=0;i<n;i++) {
            a2[a[i]-1].pb(i);
            b2[b[i]-1].pb(i);
        }
        for (int i=0;i<n;i++) {
            if (b2[i].empty()) {continue;}
            
            int ptr = b2[i].size(), ptr2 = 0;
            ll sum = 0;
            for (int x : a2[i]) { // weird spacing lol
                while (ptr2<b2[i].size() && b2[i][ptr2]<=x) {
                    ptr2++;
                }
                
                while (ptr<ptr2) { // 2p algorithm
                    sum -= n-b2[i][ptr++];
                }

                while (ptr>ptr2 && b2[i][ptr-1]>x && n-b2[i][ptr-1]<=x+1) {
                    sum += n-b2[i][--ptr];
                }
                
                ans += (ll)(x+1)*(ptr-ptr2)+sum;
            }
        }
    };
    solve();
    swap(a,b);
    solve();

    for (int i=0;i<n;i++) {
        if (a[i]==b[i]) { // side cases
            ans += min(i+1,n-i);
            ans += (ll)(i+1)*(i)/2;
            ans += (ll)(n-i)*(n-i-1)/2;
        }
    }
    cout << ans << '\n';
}