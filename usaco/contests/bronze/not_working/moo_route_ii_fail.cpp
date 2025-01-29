#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<long> flight;
vector<queue<vector<int>>> flights;
//vector<queue<bool>> states;
vector<int> layover;
vector<int> v;
//vector<int> m;

void dfs(int node, int time) {
	
	v[node]++;
	int id = v[node];
	int sz = flights[node].size();
	for (int i=0;i<sz;i++) {
		auto fl = flights[node].front();
		flights[node].pop();
		if (fl[0] >= time) {
			//cout << fl[2] << " "<<flight[fl[1]]<<" "<<flights[node].size()<<"\n"; 
			if (fl[2] < flight[fl[1]]) {
				
				//states[node][z] = 1;
				flight[fl[1]] = fl[2];
				//cout << fl[1]+1 << " " << flight[fl[1]] << endl;
				//visit[fl[1]] = 1;
				dfs(fl[1], fl[2]+layover[fl[1]]);
				if (id != v[node]) {return;}
			}
		} else {
			flights[node].push(fl);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n, m; cin >> n >> m;
	int c, r, d, s;
	flights.resize(n);layover.resize(n);//states.resize(n);
	flight.resize(n);fill(flight.begin(),flight.end(),LONG_MAX);
	v.resize(n);fill(v.begin(),v.end(),0);

	for (int i=0;i<m;i++) {
		cin >> c >> r >> d >> s; c--; d--;
		flights[c].push({r,d,s});

	}
	for (int i=0;i<n;i++) {cin >> layover[i];}

	flight[0] = 0; dfs(0,0);
	cout << 0 << "\n";
	for (int i=1;i<n;i++) {
		cout << (flight[i] == LONG_MAX ? -1 : flight[i]) << "\n";
	}
}
