#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

int main() {
    freopen("cowdate.in","r",stdin);
    freopen("cowdate.out","w",stdout);
    int n; cin >> n;
    vec<double> p(n);
    F0R(i,n) {cin >> p[i]; p[i] /= 1e6;}

    double ans = 0, sum = 0, prod = 1;
    for (int l=0,r=0;l<n;l++) {
        while (r<n && sum<=1) {
            sum += p[r]/(1-p[r]);
            prod *= 1-p[r];
            r++;
        }
        chmax(ans,sum*prod);
        sum -= p[l]/(1-p[l]);
        prod /= 1-p[l];
    }
    cout << (int)(ans*1e6) << '\n';
}