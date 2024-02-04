#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define ll long long
 
int k, n;
ll sum = 0;
vector<int> a;
 
bool check(ll m) {
    ll z = 0;
    for (int i=n/2;i<n;i++) {
        z += max((ll)0, m-a[i]);
    } return z <= k;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    for (int i=n/2;i<n;i++) {
        sum += a[i];
    }
    ll l = a[n/2]; ll h = a[n-1]+k; ll m = (l+h)/2;
    ll ans = 0;
    
    while (l <= h) {
        if (check(m)) {
            l = m+1;
            ans = m;
        } else {h = m-1;}
        m = (l+h)/2;
    }
    cout << ans << "\n";
}