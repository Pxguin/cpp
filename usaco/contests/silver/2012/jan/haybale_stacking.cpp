#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("stacking.in","r",stdin);
	freopen("stacking.out","w",stdout);
	int n, k; cin >> n >> k;
	int a, b;
	int start[n] = {0}, end[n] = {0}, stacks[n];
	ll cur = 0;

	while (k--) {
		cin >> a >> b; a--; b--;
		start[a]++; end[b]++;
	}
	for (int i=0;i<n;i++) {
		cur += start[i];
		stacks[i] = cur;
		cur -= end[i];
	}

	sort(stacks, stacks+n);
	cout << stacks[n/2] << "\n";
}
