#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int n, k;

struct SCC {
	int sz; vector<int> lo, hi;
	SCC (vector<int>& skill) : sz(1), lo(skill), hi(skill) {};
};

bool cmp1(const SCC& a, const SCC& b) {
	F0R(i,k) {if (a.lo[i]<=b.hi[i]) {return true;}}
	return false;
}
void merge(const SCC& a, SCC& b) {
	b.sz += a.sz;
	F0R(i,k) {
		b.hi[i] = max(b.hi[i],a.hi[i]);
		b.lo[i] = min(b.lo[i],a.lo[i]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	vector<int> skill(k);
	set<SCC,bool (*)(const SCC&, const SCC&)> s(cmp1);
	F0R(i,n) {
		F0R(j,k) {cin >> skill[j];}
		SCC new_ = SCC(skill);
		
		auto it = s.upper_bound(new_), it2 = s.lower_bound(new_);
        /*lower bound finds the earliest scc that beats the node (check how the cmp function works); 
        upper bound finds the earliest SCC that dominates this one, so the iterator before it must be the last SCC that this node can beat*/
		
		if (it!=s.end() && it2!=s.begin() && cmp1(*it,*prev(it2)) && cmp1(*prev(it2),new_)) {
			while (it!=it2) {
				merge(*it,new_);
				it = s.erase(it);
			} 
		} s.insert(new_);
		cout << s.rbegin()->sz << '\n';
	}
}

/*
bool cmp1(const SCC& a, const SCC& b) {return (a.lo[0]<=b.hi[0]);} 

bool upper(const SCC& a, const SCC& b) { // used to find last scc that the node beats (note this is the exact same as the current compare function)
	F0R(i,k) {if (a.lo[i]<=b.hi[i]) {return true;}}
	return false;
}

bool lower(const SCC& a, const SCC& b) { // used to find first scc that beats the node (replaced with upper bound in the final version)
	F0R(i,k) {if (a.hi[i]>b.lo[i]) {return false;}}
	return true;
}
*/