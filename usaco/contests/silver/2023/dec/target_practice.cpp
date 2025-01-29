#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, c; cin >> t >> c;
	int a;
	bool targets[2*c+1] = {false};
	for (int i=0;i<t;i++) {
		cin >> a;
		targets[a+c] = true;
	}
	string s; cin >> s;
	int pos = c;
	
	unordered_set<int> hit;

	int count = 0;
	map<int, int> hit_time;
	for (int i=0;i<c;i++) {
		if (s[i] == 'L') {pos--;}
		else if (s[i] == 'R') {pos++;}
		else {
			if (targets[pos] && !hit.count(pos)) {
				hit.insert(pos); count++;
				hit_time[i] = pos;
			}
		}
	}
	// initial simulation, if you hit a target then remember what second you hit it

	unordered_set<int> add[5];
	unordered_set<int> ss[5];
	int ans = count;

	for (int i=c-1;i>=0;i--) {
		/* calculates suffix and answer simultaneously
		 otherwise, would have to store a prefix sum and amount of (and which) targets 
		 are hit at every location for every suffix (lot more complicated+memory)*/
		if (hit_time.count(i)) {
			for (int j=0;j<5;j++) {
				if (add[j].count(pos)) {
					ss[j].insert(pos);
					add[j].erase(pos);
				}
			} 
			// if you have hit a target at this time, then it will be unhit because of 
			// the loop going back->front
			// check if any suffix sums are waiting to hit this target
			count--;
			hit.erase(hit_time[i]); 
		}

		if (s[i] == 'L') {pos++;}
		else if (s[i] == 'R') {pos--;}

		int z = 0;
		if (s[i] == 'L') {
			ans = max(ans, count+(int)(ss[4].size()));
			if (targets[pos] && !hit.count(pos) && !ss[3].count(pos)) {z = 1;}
			// if changing to a fire, need to make sure that:
			// - this is a target
			// - you haven't hit this target yet, both in the current prefix and suffix
			ans = max(ans, count+(int)(ss[3].size())+z);
		} else if (s[i] == 'R') {
			ans = max(ans, count+(int)(ss[0].size()));

			if (targets[pos] && !hit.count(pos) && !ss[1].count(pos)) {z = 1;}
			ans = max(ans, count+(int)(ss[1].size())+z);
		} else {
			ans = max(ans, count+(int)(ss[1].size()));
			ans = max(ans, count+(int)(ss[3].size()));
		}

		if (s[i] == 'F') {
			// if you fire here, check for all targets [-2, 2] units away
			// if there is a target, but it has been hit, then add it into the target waiting list
			// if it hasn't been hit, then simply hit it
			for (int j=pos-2;j<=pos+2;j++) {
				if (j > 0 && j < 2*c+1) {
					if (hit.count(j)) {
						add[j+2-pos].insert(j);
					} else {
						if (targets[j]) {
							ss[j+2-pos].insert(j);
						}
					}
				}
			}
		}
	}

	cout << ans << "\n";
}
