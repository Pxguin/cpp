#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
	int m, x; cin >> m >> x;
	
	priority_queue<int,v<int>> pq;
	int cur = 0;
	F0R(i,m) {
		int c; cin >> c;
		cur -= c; pq.push(c); // try buying current unit
		if (cur<0) { // if budget is negative, remove highest cost unit
			cur += pq.top(); pq.pop();
		}
		
		cur += x;
	} cout << pq.size() << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}