#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);

    int n; cin >> n;

    v<int> x(n);
    F0R(i,n) {cin >> x[i];}
    sort(all(x));

    if (n==2) {cout << (double)(x[1]-x[0])/2; return 0;}

    v<int> left(n,INT_MAX), right(n,INT_MAX); // dps for left and right
    left[0] = right[n-1] = 0;
    v<v<int>> del(n);
    multiset<int> r,len;
    FOR(i,1,n) { // left dp: either increase power or keep it the same
        left[i] = max(left[i-1]+1,x[i]-x[i-1]);
        if (left[lower_bound(all(x),x[i]-left[i-1])-x.begin()]<left[i-1]) {left[i]=left[i-1];}
    }
    for (int i=n-2;i>=0;i--) {
        right[i] = max(right[i+1]+1,x[i+1]-x[i]);
        if (right[--upper_bound(all(x),x[i]+right[i+1])-x.begin()]<right[i+1]) {right[i]=right[i+1];}
    }

    int ans = INT_MAX;
    len.insert(INT_MAX); r.insert(INT_MAX);
    for (int i=n-1;i>=0;i--) {
        int change = x[i]-2*right[i]-2; // when 2R+2 > len
        int it = upper_bound(all(x),change)-x.begin();
        if (it) {del[it-1].pb(i);}

        r.insert(2*right[i]+2);
        for (int idx : del[i]) {
            r.erase(r.find(2*right[idx]+2));
            len.insert(x[idx]);
        }
        chmin(ans,max(2*left[i]+2,min(*len.begin()-x[i],*r.begin()))); // combine mins
    } cout << fixed << setprecision(1) << (double)ans/2;
}