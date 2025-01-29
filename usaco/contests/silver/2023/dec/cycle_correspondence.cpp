#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;

int solve(vector<int>& a, vector<int>& b) {
    vector<int> pos(n+1, -1);
    vector<int> freq(k,0);
    for (int i=0;i<k;i++) {pos[a[i]] = i;}
    for (int i=0;i<k;i++) {
        if (pos[b[i]] != -1) {
            if (i >= pos[b[i]]) {freq[i-pos[b[i]]]++;}
            else {freq[i-pos[b[i]]+k]++;}
        }
    }
    int mx = 0;
    for (int i : freq) {mx = max(mx, i);}
    return mx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    unordered_set<int> sum;
    cin >> n >> k;
    vector<int> a(k); vector<int> b(k);
    for (int i=0;i<k;i++) {cin >> a[i]; sum.insert(a[i]);}
    for (int i=0;i<k;i++) {cin >> b[i]; sum.insert(b[i]);}
    int ans = n-sum.size();

    int x = solve(a,b);
    reverse(b.begin(), b.end());
    int y = solve(a,b);
    ans += max(x,y);
    cout << ans << "\n";
}