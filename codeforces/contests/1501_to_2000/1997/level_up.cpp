#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int n, q;
vector<int> segtree;

void add(int idx, int val, int l=0, int r=n-1, int cur=1) {
	if (l==r) {segtree[cur]+=val;}
	else {
		int m = (l+r)/2;
		if (idx<=m) {add(idx,val,l,m,2*cur);}
		else {add(idx,val,m+1,r,2*cur+1);}
		segtree[cur] = segtree[2*cur]+segtree[2*cur+1];
	}
}

int get(int l, int r, int tl=0, int tr=n-1, int cur=1) {
	if (l>r) {return 0;}
	if (l==tl&&r==tr) {return segtree[cur];}
	int m = (tl+tr)/2;
	return get(l,min(r,m),tl,m,2*cur)+get(max(l,m+1),r,m+1,tr,2*cur+1);
}

int find(int k, int tl=0, int tr=n-1, int cur=1) {
	if (k > segtree[cur]) {return -1;}
	if (tl==tr) {return tl;}
	int m = (tl+tr)/2;
	if (segtree[2*cur]>=k) {return find(k,tl,m,2*cur);}
	else {return find(k-segtree[2*cur],m+1,tr,2*cur+1);}
}

int query(int x, int k) {return find(k += get(0,x));}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> q;
	segtree.assign(4*n,0);
	vector<int> a(n);
	vector<vector<int>> del(n+1);
	F0R(i,n) {
		cin >> a[i];
		if (a[i]<n) {del[a[i]].pb(i);}
	} F0R(i,n) {add(i,1);}

	vector<pii> cur;
	F0R(i,n) {cur.pb({i+1,i});}
	for (int idx : del[1]) {add(idx,-1);}
	vector<vector<int>> ok(n+1);
	F0R(i,n) {ok[i+1].pb(i);}

	FOR(i,2,n+1) {
		vector<pii> nxt;
		for (pii x : cur) {
			int res = query(x.s,x.f);
			if (res != -1) {nxt.pb({x.f,res}); ok[x.f].pb(res);}
		} for (int idx : del[i]) {add(idx,-1);}
		cur = nxt;
	}

	// MINIMUM K SUCH THAT YOU FIGHT THIS MONSTER AAAAAAAAAAAAAAAAAAAAAAAAA
	vector<int> ans(n);
	F0R(i,n) {
		int l=1,h=n,m=(l+h)/2,res=n;
		while (l <= h) {
			if ((lower_bound(ok[m].begin(),ok[m].end(),i))-ok[m].begin()+1 <= a[i]) {h=m-1; res=m;}
			else {l=m+1;}
			m = (l+h)/2;
		} ans[i] = res;
	}
	
	while (q--) {
		int i, x; cin >> i >> x;
		cout << (ans[--i]<=x ? "YES\n" : "NO\n");
	}
}