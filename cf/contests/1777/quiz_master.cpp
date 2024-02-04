#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
vector<long long> factors[100001];
 
void solve() {
    int n, m; cin >> n >> m;
    int a[n]; for (int i=0;i<n;i++) {cin >> a[i];}
    sort(a, a+n);
    
    int count = 0;
    int p1 = 0;

    int freq[m+1];
    fill(freq, freq+m+1, 0);
    int ans = INT_MAX;
    
    for (int p2=0;p2<n;p2++) {
        for (int j : factors[a[p2]]) {
            if (j>m) {break;}
            if (++freq[j] == 1) {count++;}
        }
 
        while (count == m) {
            ans = min(ans, a[p2]-a[p1]);
            for (int j : factors[a[p1]]) {
                if (j>m) {break;}
                if (--freq[j] == 0) {count--;}
            }
            p1++;
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    
}
 
int main() {
    for (int i=1;i<100001;i++) {
        for (int j=i;j<100001;j+=i) {
            factors[j].push_back(i);
        }
    }
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}