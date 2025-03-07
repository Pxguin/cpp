#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_A = 4e5;
v<int> prime(MAX_A+1,INT_MAX);

void precalc() {
	for (int i=2;i<=MAX_A;i++) { // calculates smallest divisor of each number
		if (prime[i]==INT_MAX) {
			prime[i] = 1;
			for (int j=i*2;j<=MAX_A;j+=i) {chmin(prime[j],i);}
		}
	}
}

int solve() {
	int n; cin >> n;
	v<int> a(n);
	int p = -1;
	F0R(i,n) {
		cin >> a[i];
		if (prime[a[i]]==1) { // make sure there is no more than one prime in array
			if (p!=-1) {p = INT_MAX;}
			else {p = a[i];}
		}
	}
	chmax(p,2); // if there's no primes, set it to 2
	F0R(i,n) {
		if (a[i]==p) {continue;} // ignore if it's the prime
		if (a[i]^1 && a[i]/2<p) {return -1;} // even: works if >= 2*p
		else if (a[i]&1 && (a[i]-prime[a[i]])/2<p) {return -1;} // odd: works if >= 2*p + min divisor
	} return p;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	precalc();
	int t; cin >> t;
	while (t--) {cout << solve() << '\n';}
}