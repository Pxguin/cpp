#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define MAX_N 1000002
 
int prime[MAX_N] = {0};
 
void calc_primes() {
    for (ll i=2;i<=MAX_N;i++) {
        if (!prime[i]) {
            prime[i] = i;
            for (ll p=i*i;p<=MAX_N;p+=i) {
                if (prime[p] == 0) {prime[p] = i;}
            }
        }
    }
}
 
bool solve() {
	int n, m; cin >> n >> m;
	
	return (prime[n] <= m && n != 1);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    calc_primes();
	int t; cin >> t;
	while (t--) {cout << (solve() ? "NO" : "YES") << "\n";}
}