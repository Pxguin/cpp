#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define s second
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
	int n; cin >> n;
	string push_[4] = {"pushStack", "pushQueue", "pushFront", "pushBack"};
	string pop_[4] = {"popStack", "popQueue", "popFront", "popBack"};
	ll a;
	set<pair<int,int>> num;
 
	int last = 0;
	vector<int> ans;
 
	for (int i=0;i<n;i++) {
		cin >> a;
		
		if (a != 0) {num.insert(mp(a, i-last)); ans.pb(3);}
		else {
			last = i+1;
 
			int k = min(3, (int)num.size());
			int it2 = 0;
			for (auto it=num.rbegin(); it!=num.rend(); it++) {
				ans[it->s] = min(k, it2);
				it2++;
			}
 
			for (int j : ans) {
				cout << push_[j] << "\n";
			}
			cout << k;
			for (int j=0;j<k;j++) {
				cout << " " << pop_[j];
			} 
			cout << "\n";
			ans.resize(0);
			num.clear();
		}
	}
	for (int j : ans) {cout << push_[3] << "\n";}
}