#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define mp make_pair

struct Person {
	int a, b, i;
	Person (int a1, int b1, int i1) : a(a1), b(b1), i(i1) {};
	bool operator<(const Person& y) const {return a < y.a;}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<Person> people;
	for (int i=0;i<n;i++) {
		int a, b; cin >> a >> b;
		people.pb(Person(a,b,i));
	}
	sort(people.begin(), people.end());

	set<pii> rooms;
	int cur = 0;
	vector<int> waiting;
	int ans[n];

	for (Person& p : people) {
		while (rooms.size() && rooms.begin()->f < p.a) {
			waiting.pb(rooms.begin()->s);
			rooms.erase(rooms.begin());
		}
		if (waiting.empty()) {cur++; waiting.pb(cur);}
		ans[p.i] = waiting.back();
		rooms.insert(mp(p.b, waiting.back()));
		waiting.pop_back();
	}
	cout << cur << '\n';
	for (int i : ans) {cout << i << ' ';}
}
