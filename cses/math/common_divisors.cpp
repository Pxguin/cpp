#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int x; v<int> freq(1e6+1,0);
    F0R(i,n) {
        cin >> x;
        freq[x]++; // frequency array
    }

    int ans = 0;
    FOR(i,1,1e6+1) { // go through each candidate for gcd
        int c = 0;
        for (int j=i;j<=1e6;j+=i) {c += freq[j];} // count how many numbers divide this candidate
        if (c>=2) {ans = i;} // works if >= 2 numbers divide it
    }
    cout << ans << '\n';
}