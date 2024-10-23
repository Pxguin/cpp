#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll mod = (1LL<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
ll b = uniform_int_distribution<ll>(0,mod-1)(rng);

ll add(ll a, ll b) {return (a+b)%mod;}
ll sub(ll a, ll b) {return (a+mod-b)%mod;}
ll mul(ll a, ll b) {return (__int128)a*b%mod;}

void solve() {
	int n, k; cin >> n >> k;
	vector<string> s(n);
	vector<vector<ll>> hsh(n,vector<ll>(k+1,0));
	vector<ll> exp(k+1,1);
	F0R(i,n) {cin >> s[i];}
	F0R(i,k) {exp[i+1]=mul(exp[i],b);}
	vector<int> ans(n,0);
	
	if (n<k) {
		F0R(i,n) {
			FOR(j,i+1,n) {
				int ctr = 0;
				F0R(p,k) {ctr += (s[i][p]!=s[j][p]);}
				ans[i] |= (ctr<3); ans[j] |= (ctr<3);
			} 
		}
	} else {
		F0R(i,n) {
			F0R(j,k) {hsh[i][j+1] = add(hsh[i][j],mul(s[i][j],exp[j]));};
		}
		F0R(i,k) {
			FOR(j,i,k) {
				unordered_map<ll,int> tot;
				vector<ll> hsh2;
				F0R(x,n) {
					ll q1 = hsh[x][i], q2 = sub(hsh[x][j],hsh[x][i+1]), q3 = sub(hsh[x][k],hsh[x][j+1]);
					hsh2.pb(add(add(q1,q2),q3));
					tot[hsh2.back()]++;
				}
				F0R(i,n) {if (tot[hsh2[i]]>1) {ans[i]|=1;}}
			}
		}
	}
	for (int i : ans) {cout<<i;} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}