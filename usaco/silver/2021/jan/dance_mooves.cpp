#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n,k; cin >> n >> k;
	vector<vector<int>> to(n);
	vector<int> pos;
	for (int i=0;i<n;i++) {pos.push_back(i);}
	
	int a, b;
	for (int i=0;i<k;i++) {
		cin >> a >> b;
		a--; b--;
		to[pos[a]].push_back(b); 
		to[pos[b]].push_back(a); 
		swap(pos[a], pos[b]);
	}
	vector<int> ans(n,-1);

	for (int i=0;i<n;i++) {
		if (ans[i] != -1) {continue;}
		if (to[i].empty()) {ans[i] = 1;}
		else {
			vector<int> cycle;
			int j = i;
			unordered_set<int> s;
			do {
				cycle.push_back(j);
				for (int p : to[j]) {s.insert(p);}
				j = *(to[j].rbegin());
			} while (j != i);
			
			for (int c : cycle) {ans[c] = (int)s.size();}
		}
	}
	for (int i : ans) {cout << i << "\n";}
}
