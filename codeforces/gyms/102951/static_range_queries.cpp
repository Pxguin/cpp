#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

struct Update {
	int l, r, v;
	Update (int l, int r, int v) : l(l),r(r),v(v) {};
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, q, l, r, v; cin >> n >> q;
	vector<Update> upd; vector<pii> query;
	map<int,int> nums,inv;
	F0R(i,n) {
		cin >> l >> r >> v; 
		nums[l]=nums[r-1]=0;
		upd.pb(Update(l,r-1,v));
	} F0R(i,q) {
		cin >> l >> r;
		query.pb({l-1,r-1});
		nums[l-1]=nums[r-1]=0;
	} int idx = 0;
	for (pii x : nums) {nums[x.f] = idx; inv[idx++]=x.f;}
	vector<ll> ps(nums.size(),0), sub(nums.size(),0);

	for (Update x : upd) {
		ps[nums[x.l]] += x.v;
		sub[nums[x.r]] += x.v;
	} 
	ll cur = ps[0];
	FOR(i,1,ps.size(),1) {
		cur += ps[i];
		ps[i] += ps[i-1]+((cur-ps[i])*(inv[i]-inv[i-1]));
		cur -= sub[i];
	} 
	for (pii x : query) {cout << ps[nums[x.s]]-ps[nums[x.f]] << '\n';}
} 	