#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    map<int,int> freq;
    int p = 1, d = 1;
    ll ans = 0;
    freq[a[0]]++;

    F0R(i,n) {
        while (p<n && (d<k || freq[a[p]])) { // increment ptr while no more than k distinct
            if (++freq[a[p]]==1) {d++;}
            p++;
        }
        ans += p-i; // amt of subarrays for this i
        if (--freq[a[i]]==0) {d--;}
    } cout << ans << '\n';
}