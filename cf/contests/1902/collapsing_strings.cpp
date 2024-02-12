#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
struct Trie {
	Trie* adj[27];
	ll cnt2;
	ll cnt;
	Trie() {
		cnt2 = 0;
		cnt = 0;
		for (int i=0;i<27;i++) {adj[i] = NULL;}
	}
};
 
void insert_string(Trie* rt, string& val) {
	for (char c : val) {
		int idx = c-'a';
		if (rt->adj[idx] == NULL) {
			Trie *x = new Trie();
			rt->adj[idx] = x; 
		}
		rt = rt->adj[idx];
		rt->cnt++;
	}
	rt->cnt2++;
}
 
ll search(Trie* rt, string& val) {
	ll ret = 0;
	val += "{";
	for (ll i=0;i<val.size();i++) {
		char c = val[i];
		int idx = c-'a';
		if (rt->adj[idx] != NULL) {
			ret += ((rt->cnt)-(rt->adj[idx]->cnt))*(i)*2LL;
			rt = rt->adj[idx];
		} else {
			ret += (rt->cnt)*(i)*2LL; break;
		}
	}
	return ret;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	ll n; cin >> n;
	string s[n];
 
	Trie* rt = new Trie();
	ll ans = 0;
	ll sum = 0;
 
	for (int i=0;i<n;i++) {
		cin >> s[i];
		insert_string(rt, s[i]);
		sum += s[i].size();
	}
 
	for (int i=0;i<n;i++) {
		reverse(s[i].begin(), s[i].end());
		ans += (sum+(ll)s[i].size()*n)-search(rt, s[i]);
	}
	cout << ans << "\n";
}