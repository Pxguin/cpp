#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);

    int n; cin >> n;
    v<int> c(n);
    int ptr = 0;
    F0R(i,n) {
        cin >> c[i];
        if (c[i]) {ptr=i;}
    }

    ll ans = 1e18;

    for (int i=ptr+1;i<ptr+n;i++) { // pick the endpoint of the first range
        int cur = ptr, left = c[ptr];
        ll cand = 0;
        for (int j=i+n;j>i;j--) { // greedily go backwards and assign cows
            int p = j%n;
            
            left--;
            cand += ((j-cur+n)%n)*((j-cur+n)%n);
            while (left==0) {
                cur = (cur-1+n)%n;
                left = c[cur];
            }
        } chmin(ans,cand);
    } cout << ans << '\n';
}