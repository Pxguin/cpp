#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    map<int,int> freq;
    for (int i=0;i<2*n;i++) {
        int a; cin >> a;
        freq[a]++;
    }
    bool flag = false;
    int cnt = 0;
    for (auto[x,w] : freq) {
        if (x>=(m+1)/2) {continue;}
        if (m%2) {
            if (w%2) {flag = true;} // when m is odd
        } else {
            if (w%2 != freq[x+(m/2)]%2) {flag = true;} // when m is even
            else if (w%2) {cnt++;}
        }
    } cout << (flag || cnt%2 ? "Alice" : "Bob");
}