#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define mp make_pair
#define s second

void solve() {
	int n; cin >> n;
	ll dmg[n];
	int atk[n+1];
	atk[n] = 0;
	set<int> alive;
	set<int> rel;

	for (int i=0;i<n;i++) {
		cin >> atk[i]; alive.insert(i);
	} for (int i=0;i<n;i++) {
		cin >> dmg[i]; dmg[i]*=-1;
	}
	for (int i=0;i<n;i++) {
		if (i < n-1) {dmg[i] += atk[i+1];}
		if (i < n-1) {dmg[i+1] += atk[i];}
		if (dmg[i] > 0) {rel.insert(i);}
	}

	int ans;
	
	for (int i=0;i<n;i++) {
		set<int> nxt;
		ans = 0;
		for (int m : rel) {
			auto it = alive.find(m);
			if (it != alive.end()) {
				ans++;
				int p = n, p2 = n;
				if (it != alive.begin()) {p = *prev(it);nxt.insert(*prev(it));}
				if (it != prev(alive.end())) {p2 = *next(it);nxt.insert(*next(it));}

				alive.erase(m);
				if (p != n) {
					dmg[p] += atk[p2]-atk[m]; 
					nxt.insert(p);
					if (dmg[p] <= 0) {nxt.erase(p);}
				}
				if (p2 != n) {
					dmg[p2] += atk[p]-atk[m]; 
					nxt.insert(p2);
					if (dmg[p2] <= 0) {nxt.erase(p2);}
				}
				dmg[m] = -999;
			}
		}
		
		rel = nxt;

		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
	while (t--) {solve();}
}