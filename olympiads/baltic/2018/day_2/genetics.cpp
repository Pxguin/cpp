#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)

vector<bool> prime(38922,true);
vector<int> primes;
int mod = 1e9+7;
void calc() {
	for (int i=2;i*i<=38921;i++) {
		if (prime[i]) {
			for (int j=i*i;j<=38921;j+=i) {prime[j]=false;}
		}
	}
	for (int i=2;i<=38921;i++) {
		if (prime[i]) {primes.pb(i);}
	}
}
ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return (a+b)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	calc();

	vector<vector<ll>> hsh(m,vector<ll>(4));
	char c[4] = {'A','C','T','G'};
	vector<vector<char>> gen(n,vector<char>(m));
	F0R(i,n) {
		F0R(j,m) {cin >> gen[i][j];}
	}
	F0R(pos,m) {
		F0R(ch,4) {
			ll h = 1;
			F0R(cow,n) {
				if (gen[cow][pos]==c[ch]) {h = mul(h,primes[cow]);}
			} hsh[pos][ch] = h;
		}
	}
	F0R(cow,n) {
		ll t = 1;
		F0R(j,n) {
			if (cow!=j) {t = mul(t,primes[j]);}
		} 
		ll target = 1;
		F0R(j,k) {target = mul(target,t);}
		ll h = 1;

		F0R(pos,m) {
			F0R(ch,4) {
				if (c[ch]!=gen[cow][pos]) {h = mul(h,hsh[pos][ch]);}
			}
		} 
		if (h==target) {cout << cow+1 << '\n'; break;}
	}
}