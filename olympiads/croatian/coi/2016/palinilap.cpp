#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector

using T = __int128;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
ll mod = (1LL<<61)-1, b = uniform_int_distribution<ll>(0, 10000)(rng);
ll mul(ll a, ll b) {return (__int128)a*b%mod;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    s = '0'+s;

    v<T> fac(n+1,0), hsh(n+1,0), hsh2(n+2,0);
    fac[0] = 1;
    for (int i=0;i<n;i++) {
        fac[i+1] = fac[i]*b%mod;
        hsh[i+1] = ((fac[i]*(s[i+1]-'a'+1)%mod)+hsh[i])%mod;
        hsh2[n-i] = ((fac[i]*(s[n-i]-'a'+1)%mod)+hsh2[n-i+1])%mod;
    }
    auto check = [&](int l1, int r1, int l2, int r2) { // compare equality of strings [l1,r1], [r2,l2]
        int p1 = l1, p2 = n-l2+1;
        T h1 = (hsh[r1]-hsh[l1-1]+mod)%mod, h2 = (hsh2[r2]-hsh2[l2+1]+mod)%mod;

        if (p1<p2) {h1 = mul(h1,fac[p2-p1]);}
        else {h2 = mul(h2,fac[p1-p2]);}

        return (h1==h2);
    };
    
    v<v<ll>> change(n+1,v<ll>(26,0));
    v<ll> ps(n+3,0), pal(n+1);
    ll tot = 0;

    auto calc = [&](int i1, int i2, int doit) {
        int l = 0, h = min(i1-1,n-i2), m = (l+h)/2, ans;
        while (l <= h) { // find longest palindrome centered at [i1,i2]
            if (check(i2+1,i2+m,i1-1,i1-m)) {
                l = m+1;
                ans = m;
            } else {h = m-1;}
            m = (l+h)/2;
        }

        if (doit) {return ans;} // this is just for a side case
        
        // update prefix sum/diff array with this palindrome
        if (i1==i2) {pal[i1] += ans+1;} // if i1=i2, then changing either one removes all palindromes (so don't count them)
        ps[i1-ans]++; ps[i1+1]--;
        ps[i2+1]--; ps[i2+ans+2]++;
        tot += ans+1; // total number of palindromes

        if (ans!=min(i1-1,n-i2)) { // find maximum palindrome with 1 strike
            l = ans+2, h = min(i1-1,n-i2), m = (l+h)/2; int ans2 = 0;
            while (l <= h) {
                if (check(i2+ans+2,i2+m,i1-ans-2,i1-m)) {
                    l = m+1;
                    ans2 = m-(ans+1);
                } else {h = m-1;}
                m = (l+h)/2;
            }
            change[i1-ans-1][s[i2+ans+1]-'a'] += ans2+1; // update
            change[i2+ans+1][s[i1-ans-1]-'a'] += ans2+1;
        }
        return 0;
    };
    for (int i=1;i<=n;i++) {
        calc(i,i,0); // single center
        
        if (i<n) {
            if (s[i]==s[i+1]) {calc(i,i+1,0);} // existing double center
            else {
                int z = calc(i,i+1,1)+1; // change a letter to make double center
                change[i][s[i+1]-'a'] += z;
                change[i+1][s[i]-'a'] += z;
            }
        }
    }
    ll ans = tot;
    for (int i=1;i<=n;i++) { // update difference arrays
        ps[i+1] += ps[i];
    }
    for (int i=1;i<=n;i++) {
        ps[i+1] += ps[i];
        ps[i] -= pal[i];
        ll add = 0;
        for (int j=0;j<26;j++) {add = max(add,change[i][j]);} // find best option to change this letter
        ans = max(ans,tot-ps[i]+add); // total palindromes - amount removed by changing + amount gained by changing
    }
    cout << ans << '\n';
}