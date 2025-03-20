#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_A = 5e5;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    
    int n, c; cin >> n >> c;
    c--;

    v<int> freq(MAX_A,0);
    v<int> mn(MAX_A,1e6);
    int ans = 0;

    F0R(i,n) {
        int a; cin >> a;
        freq[--a]++;
        if (a==c) {continue;} // side case
        chmin(mn[a],freq[a]-1-freq[c]); // find the minimum left endpoint value
        chmax(ans,freq[a]-freq[c]-mn[a]); // test for this right endpoint
    }
    cout << ans+freq[c] << '\n';
}