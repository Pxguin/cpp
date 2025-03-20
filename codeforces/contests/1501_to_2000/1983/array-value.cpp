#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define chmin(a, b) a = min(a,b)

struct Trie {
	Trie *to[2] = {};
	int mn = INT_MAX; // min index that passes through this node
};

void add(Trie *rt, int x, int idx) {
	Trie *cur = rt;
	for (int i=29;i>=0;i--) {
		bool s = x&(1<<i);
		if (cur->to[s]==NULL) {cur->to[s] = new Trie;}
		cur->to[s]->mn = idx;
		cur = cur->to[s];
	}
}

int query(Trie *rt, int x, int left, int lim) {
	Trie *cur = rt;
	int res = 0;
	for (int i=29;i>=0;i--) {
		bool s = x&(1<<i);
		if (cur->to[s]!=NULL && cur->to[s]->mn <= lim && cur->to[s]->mn > left) {cur = cur->to[s];}
		else {
			cur = cur->to[!s];
			res += (1<<i);
		}
	} return res;
}

void remove(Trie *rt, int x) {
	Trie *cur = rt;
	for (int i=29;i>=0;i--) {
		bool s = x&(1<<i);
		cur->to[s]->mn = INT_MAX;
		cur = cur->to[s];
	}
}

Trie tr;

void solve() {
	ll n, k; cin >> n >> k;
	vector<int> a(n);
	F0R(i,n) {cin >> a[i];}

	int l=0, h=1<<30, m=(l+h)/2;
	int ans = 0;

	while (l <= h) { // min M such that >= K subarrays with value <= M
		ll cand = 0;
		add(&tr,a[n-1],n-1);
		int right = n-1;
		for (int i=n-2;i>=0;i--) {
			while (right>i && query(&tr,a[i],i,right) <= m) {right--;}
			cand += (ll)n-right-1;
			add(&tr,a[i],i);
		}
		if (cand >= k) {ans = m; h = m-1;}
		else {l = m+1;}
		m = (l+h)/2;
	} cout << ans << '\n';
	F0R(i,n) {remove(&tr,a[i]);}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}
