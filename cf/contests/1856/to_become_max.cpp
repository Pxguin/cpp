#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;
 
int n, x, k;

bool check(vector<int>& a) {
    for (int i=0;i<n-1;i++) {
        long long ctr = x-a[i]; if (ctr > k) {continue;}
        int p1 = i+1;
        bool works = true;
        while (a[p1] < x-(p1-i)) {
            if (p1 == n-1) {works = false; break;}
 
            ctr += (x-(p1-i))-a[p1];
            if (ctr > k) {works = false; break;}
            p1++;
        }
        if (works) {return true;}
    }
    return false;
}
 
void solve() {
    cin >> n >> k;
    int l = 0; int h;
    vector<int> a(n);
 
    for (int i=0;i<n;i++) {
        cin >> a[i];
        l = max(l, a[i]);
    }
    h = l+k; x = (l+h)/2;
    int ans = l;
 
    while (l <= h) {
        if (check(a)) {
            l = x+1;
            ans = x;
        } else {h = x-1;}
        x = (l+h)/2;
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}