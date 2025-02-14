#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll mod = 1e9+7;
ll b = 2, b2 = 3;

ll add(ll a, ll b) {return (a+b)%mod;}
ll sub(ll a, ll b) {return (a+mod-b)%mod;}
ll mul(ll a, ll b) {return (a*b)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	char c1;
	// * is smaller than .
	vector<vector<ll>> a(2*n+1,vector<ll>(2*m+1,0)); // hashed grid
	vector<vector<char>> o(2*n+1,vector<char>(2*m+1)); // original grid
	FOR(i,1,n+1) {
		FOR(j,1,m+1) {
			cin >> c1; 
			a[i][j] = a[i+n][j] = a[i][j+m] = a[i+n][j+m] = (c1=='.')+1;
			o[i][j] = o[i+n][j] = o[i][j+m] = o[i+n][j+m] = c1;
		}
	}
	int r = 1, c = 1;
	vector<ll> exp(2*n+1,1), exp2(2*m+1,1);
	F0R(i,2*n) {exp[i+1]=mul(exp[i],b);}
	F0R(i,2*m) {exp2[i+1]=mul(exp2[i],b2);}
	FOR(i,1,2*n+1) {
		FOR(j,1,2*m+1) {
			a[i][j] = mul(a[i][j],mul(exp[i],exp2[j]));
			a[i][j] = sub(add(add(a[i][j],a[i-1][j]),a[i][j-1]),a[i-1][j-1]);
		}
	}
	auto get = [&](int a1, int b1, int c1, int d1)->ll {
		ll ret = add(sub(sub(a[c1][d1],a[a1-1][d1]),a[c1][b1-1]),a[a1-1][b1-1]);
		return ret;
	};
	auto cmp = [&](int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2)->bool {
		ll hsh = get(a1,b1,c1,d1), hsh2 = get(a2,b2,c2,d2);
		if (a2>a1) {hsh=mul(hsh,exp[a2-a1]);}
		else {hsh2=mul(hsh2,exp[a1-a2]);}
		if (b2>b1) {hsh=mul(hsh,exp2[b2-b1]);}
		else {hsh2=mul(hsh2,exp2[b1-b2]);}
		return (hsh==hsh2);
	};

	FOR(i,1,n+1) {
		FOR(j,1,m+1) {
			int l = 1, h = n*m, mid = (l+h)/2;
			int work = 0;
			while (l <= h) {
				int flag = 1;
				int div = mid/m, rem = mid%m;
				if (div) {flag &= cmp(i,j,i+div-1,j+m-1, r,c,r+div-1,c+m-1);}
				if (rem) {flag &= cmp(i+div,j,i+div,j+rem-1, r+div,c,r+div,c+rem-1);}
				
				if (flag) {l = mid+1; work = mid;}
				else {h = mid-1;}
				mid = (l+h)/2;
			}

			if (work != n*m) { // side cases: nothing works, everything works (only have to consider second one)
				if (o[i+work/m][j+work%m]<o[r+work/m][c+work%m]) {r = i; c = j;}
			}
		}
	}
	F0R(i,n) {
		F0R(j,m) {cout << o[i+r][j+c];} cout << '\n';
	}
}