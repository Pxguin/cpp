#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
 
vector<int> a;
vector<vector<pair<int,int>>> d;
int n;
 
bool check(int z) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 
	for (int i=0;i<n;i++) {
		for (pair<int,int> j : d[i]) {pq.push(j);}
 
		int ctr = z;
 
		while (pq.size() && ctr > 0) {
			pair<int,int> e = pq.top();
 
			if (e.f < i) {return false;}
			
			pq.pop();
			if (e.s > ctr) {
				e.s -= ctr;
				ctr = 0;
				pq.push(e);
			} 
			ctr -= e.s;
		}
	}
 
	return !pq.size();
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin >> n;
	int x;
	int l=0, h=0, m;
	d.resize(n);
 
	for (int i=0;i<n;i++) {cin >> x; a.pb(x); h = max(h, x);}
	for (int i=0;i<n;i++) {
		cin >> x; d[max(0, i-x)].pb(mp(min(n-1,i+x),a[i]));
	}
 
	m = (l+h)/2;
	int ans = h;
	while (l <= h) {
		if (check(m)) {
			h = m-1;
			ans = m;
		} else {l = m+1;}
		m = (l+h)/2;
	}
 
	cout << ans << "\n";
}
