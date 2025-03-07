#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5;
int prime[MAX_N+1] = {0};
bool semiprime[MAX_N+1];

void calc() { // calc all primes and semiprime numbers
    v<ll> primes;
    for (ll i=2;i<=MAX_N;i++) {
        if (!prime[i]) {
            prime[i] = i;
            primes.pb(i);
            for (ll j=i*i;j<=MAX_N;j+=i) {prime[j] = i;}
        }
    }

    int p2 = primes.size()-1;
    F0R(p1,primes.size()) {
        while (p2>p1+1 && primes[p1]*primes[p2]>MAX_N) {p2--;}
        for (int j=p1;j<=p2;j++) {semiprime[primes[p1]*primes[j]] = true;}
    }
}

void solve() {
    int n; cin >> n;
    v<int> a(n);
    v<ll> freq(n+1,0);
    F0R(i,n) {
        cin >> a[i];
        freq[a[i]]++;
    }

    ll ans = 0, primes = 0;
    for (int i=2;i<=n;i++) {
        if (semiprime[i]) {ans += freq[i]*(freq[i]+1)/2;} // pick a_i=a_j
        
        if (prime[i]==i) {
            for (int j=2*i;j<=n;j+=i) {
                if (prime[j/i]==j/i) {ans += freq[i]*freq[j];} // one is a prime multiple of the other
            }
            ans += primes*freq[i]; // both are just primes
            primes += freq[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    calc();

    int t; cin >> t;
    while (t--) {solve();}
}