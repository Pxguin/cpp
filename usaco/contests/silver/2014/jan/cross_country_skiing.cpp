#include <iostream>
#include <vector>
using namespace std;

int wps = 0;
int wpctr = 0;
int m, n;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

// flood fill
void solve(pair<long,long> wp, long d, vector<vector<long>>& v, vector<vector<long>>& e, vector<vector<long>>& w) {
	if (!v[wp.first][wp.second]) { // if not visited
		v[wp.first][wp.second] = 1;
	} else {return;}
	if (w[wp.first][wp.second] == 1) {wpctr++;}
	for (int i=0;i<4;i++) {
		if (wp.first+dx[i] >= 0 && wp.first+dx[i] < m 
		&& wp.second+dy[i] >= 0 && wp.second+dy[i] < n){ // if this index exists
			if (abs(e[wp.first+dx[i]][wp.second+dy[i]] - e[wp.first][wp.second]) <= d) { // if the elevation <= d
				solve(make_pair(wp.first+dx[i],wp.second+dy[i]), d, v, e, w);
			}
		}
	}
}

int main() {
	freopen("ccski.in","r",stdin); freopen("ccski.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	long e;
	vector<vector<long>> elevations(m);
	vector<vector<long>> waypoints(m);
	vector<vector<long>> visited(m);
	long l = 0; long h = 0;
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cin >> e;
			elevations[i].push_back(e);
			h = max(h,e);
		}
	}
	pair<int,int> wp;
	for (int i=0;i<m;i++) {
		elevations.push_back({});
		waypoints.push_back({});
		visited.push_back({});
		for (int j=0;j<n;j++) {
			cin >> e;
			waypoints[i].push_back(e);
			visited[i].push_back(0);
			if (e == 1) {wp = make_pair(i,j); wps++;}
		}
	}
	long d = (l+h)/2;
	long last;
	while (l <= h) {
		wpctr = 0; // waypoint counter
		solve(wp, d, visited, elevations, waypoints);
		int res = (wpctr == wps);

		if (res) {
			h = d-1; last = d;
		} else {l = d+1;}
		d = (l+h)/2;
		for (int i=0;i<m;i++) {
			for (int j=0;j<n;j++) {visited[i][j] = 0;}
		}
	}
	cout << last;
}
