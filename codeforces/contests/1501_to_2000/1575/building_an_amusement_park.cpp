#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    int n, k; cin >> n >> k;
    vec<ll> x(n), y(n);
    vec<double> at(n), d(n);
    for (int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
        at[i] = atan2(y[i],x[i]);
        d[i] = sqrt(x[i]*x[i]+y[i]*y[i]);
    }

    const double eps = 1e-5, pi = 2*acos(-1);
    double l = 0, h = 2e5, r = (l+h)/2, ans = 0;
    while (h-l>=eps) {
        vec<pair<double,int>> sweep;
        int mx = 0, cur = 0;
        for (int i=0;i<n;i++) {
            if (x[i]==0 && y[i]==0) {cur++; continue;}
            if (d[i]>2*r) {continue;}
            double b = acos(d[i]/2/r);

            sweep.pb({at[i]-b,-1}); sweep.pb({at[i]+b,1});
            sweep.pb({at[i]-b-pi,-1}); sweep.pb({at[i]+b-pi,1});
        }
        mx = cur;
        sort(all(sweep));
        for (int i=0;i<sweep.size();i++) {
            cur -= sweep[i].s;
            chmax(mx,cur);
        }
        if (mx>=k) {h = r; ans = r;}
        else {l = r;}
        r = (l+h)/2;
    }
    cout << fixed << setprecision(4) << ans << '\n';
}