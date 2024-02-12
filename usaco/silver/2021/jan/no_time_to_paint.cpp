#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> states;
vector<int> ps1;
vector<int> ps2;
vector<int> str;
int cmax = 0;

void solve(vector<int>& ps) {
	int sum = 0;
	for (int i=1;i<str.size()-1;i++) {
		
		if (states[str[i]] == 0 && (str[i] != str[i-1])) {
			sum++;
			states[str[i]] = 1;
		}
		
		if (str[i] < str[i-1]) {
			for (int j=str[i]+1;j<=cmax;j++) {
				states[j] = 0;
			}
		}
		ps.push_back(sum);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, q;
	char c;
	str.push_back(-1);
	cin >> n >> q;

	for (int i=0;i<n;i++) {
		cin >> c;
		str.push_back((int)c-(int)'A');
		cmax = max((int)c-(int)'A',cmax);
	}
	str.push_back(-1); ps1.push_back(0); ps2.push_back(0);

	for (int i=0;i<cmax+1;i++) {states.push_back(0);}
	solve(ps1);
	for (int i=0;i<cmax+1;i++) {states[i] = 0;}
	reverse(str.begin(),str.end());
	solve(ps2);

	int a, b;
	for (int i=0;i<q;i++) {
		cin >> a >> b;
		cout << (ps1[a-1] + ps2[n-b]) << "\n";
	}
}
