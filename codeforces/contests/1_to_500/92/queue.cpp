#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	v<int> a(n), idx(n);
	F0R(i,n) {cin >> a[i]; idx[i]=i;}
	reverse(all(a)); // to make it a bit easier
	
	sort(all(idx),[&](int x, int y) {return a[x]<a[y];});
	idx.pb(n); a.pb(1e9+1);
	
	int ptr = 0, mn = INT_MAX;
	v<int> ans(n);
	F0R(i,n+1) {
	    if (a[idx[ptr]]!=a[idx[i]]) { // update in blocks of a_i
	        FOR(j,ptr,i) { // check if a minimum exists
	            ans[idx[j]] = (idx[j]<mn ? -1 : idx[j]-mn-1);
	        }
	        FOR(j,ptr,i) { // update the minimum
	            chmin(mn,idx[j]);
	        }
	        ptr = i; i--;
	    }
	} 
    F0R(i,n) {cout << ans[n-i-1] << ' ';}
    cout << '\n';
}