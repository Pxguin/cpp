#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    int n; cin >> n;
    vec<int> a(n); vec<char> s(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n;i++) {cin >> s[i];}

    char last = s[0];
    int len = 0, ans = 0, m = 1;
    vec<int> dp = {a[0]};

    for (int i=1,j=0;i<n;i++) {
        while (j<n && s[j]==last) {len++; j++;} // find length of lis/lds that is needed

        if (dp.size()!=len+1) { // if haven't reached that length then add to lis/lds
            int j = upper_bound(all(dp),a[i]*m)-dp.begin();
            if (j==dp.size()) {dp.pb({a[i]*m}); ans++;}
            else {dp[j] = a[i]*m;}
        }
        if (dp.size()==len+1) { // else reset
            last = (last=='U' ? 'D' : 'U'); m *= -1; len = 0;
            dp = {-dp.back()};
        }
        
    } cout << ans << '\n';
}