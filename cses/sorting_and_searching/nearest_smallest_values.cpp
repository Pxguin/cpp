#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define mp make_pair
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int x;
	stack<pair<int,int>> s;
	s.push(mp(0,0));
	for (int i=0;i<n;i++) {
		cin >> x;
		while (s.top().f >= x) {s.pop();}
		cout << s.top().s << " ";
		s.push(mp(x,i+1));
	}
}
