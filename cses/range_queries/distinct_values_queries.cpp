#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using idx_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q, a; cin >> n >> q;
	idx_set<int> s;

	map<int,int> last;
	vector<pii> ranges;
	F0R(i,n) {
		cin >> a;
		if (last.find(a)!=last.end()) {ranges.pb({last[a],i});}
		last[a] = i;
	}
	
	vector<pair<pii,int>> queries(q);
	F0R(i,q) {cin >> queries[i].f.f >> queries[i].f.s; queries[i].s=i;}
	sort(queries.begin(),queries.end());
	sort(ranges.begin(),ranges.end());
	vector<int> ans(q);

	while (queries.size()) {
		auto [cur, idx] = queries.back(); queries.pop_back();
		cur.f--; cur.s--;
		while (ranges.size()&&ranges.back().f>=cur.f) {
			s.insert(ranges.back().s); ranges.pop_back();
		} ans[idx] = (cur.s-cur.f+1)-s.order_of_key(cur.s+1);
	}
	F0R(i,q) {cout << ans[i] << '\n';}
}#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using idx_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q, a; cin >> n >> q;
	idx_set<int> s;

	map<int,int> last;
	vector<pii> ranges;
	F0R(i,n) {
		cin >> a;
		if (last.find(a)!=last.end()) {ranges.pb({last[a],i});}
		last[a] = i;
	}
	
	vector<pair<pii,int>> queries(q);
	F0R(i,q) {cin >> queries[i].f.f >> queries[i].f.s; queries[i].s=i;}
	sort(queries.begin(),queries.end());
	sort(ranges.begin(),ranges.end());
	vector<int> ans(q);

	while (queries.size()) {
		auto [cur, idx] = queries.back(); queries.pop_back();
		cur.f--; cur.s--;
		while (ranges.size()&&ranges.back().f>=cur.f) {
			s.insert(ranges.back().s); ranges.pop_back();
		} ans[idx] = (cur.s-cur.f+1)-s.order_of_key(cur.s+1);
	}
	F0R(i,q) {cout << ans[i] << '\n';}
}