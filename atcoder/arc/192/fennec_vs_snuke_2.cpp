#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int freq[2] = {0};
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        freq[a%2]++;
    }
    if (n==1) {cout << "Fennec";}
    else if (n==2) {cout << "Snuke";}
    else if (n==3) {cout << (freq[1] ? "Fennec" : "Snuke");}
    else {
        freq[0] %= 2; freq[1] %= 2;
        if (!freq[0]&&!freq[1] || freq[0]&&!freq[1]) {cout << "Snuke";}
        else {cout << "Fennec";}
    }
}