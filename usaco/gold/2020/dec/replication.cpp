#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

using T = pair<int,pair<int,int>>;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
	int n, d; cin >> n >> d;
	vector<vector<char>> a(n,vector<char>(n));
	queue<T> rocks, ori, sq;
	vector<vector<int>> rock_dist(n,vector<int>(n,INT_MAX));
	vector<vector<int>> ori_dist(n,vector<int>(n,INT_MAX));
	vector<vector<int>> sq_dist(n,vector<int>(n,INT_MAX));
	vector<T> wait;
	F0R(i,n) {
		F0R(j,n) {
			cin >> a[i][j];
			if (a[i][j]=='#') {
				rocks.push({0,{i,j}}); rock_dist[i][j] = 0;
			} else if (a[i][j]=='S') {
				ori.push({0,{i,j}}); ori_dist[i][j] = 0;
			}
		}
	}

	// bfs from rocks
	while (rocks.size()) {
		T cur = rocks.front(); rocks.pop();
		F0R(i,4) {
			pii x = {cur.s.f+dx[i], cur.s.s+dy[i]};
			if (x.f<0 || x.f>=n || x.s<0 || x.s>=n) {continue;}
			if (rock_dist[x.f][x.s]!=INT_MAX) {continue;}
			rock_dist[x.f][x.s] = cur.f+1;
			rocks.push({cur.f+1,{x.f,x.s}});
		}
	}
	// bfs from start points
	while (ori.size()) {
		T cur = ori.front(); ori.pop();
		int r = cur.f/d;
		if (rock_dist[cur.s.f][cur.s.s]<=r) {continue;}
		F0R(i,4) {
			pii x = {cur.s.f+dx[i], cur.s.s+dy[i]};
			if (x.f-r<0 || x.f+r>=n || x.s-r<0 || x.s+r>=n) {continue;}
			if (ori_dist[x.f][x.s]!=INT_MAX || rock_dist[x.f][x.s]<=r) {continue;}
			ori_dist[x.f][x.s] = cur.f+1;
			ori.push({cur.f+1,{x.f,x.s}});
		}
	}
	F0R(i,n) {
		F0R(j,n) {
			if (ori_dist[i][j]==INT_MAX) {continue;}
			wait.pb({ori_dist[i][j]/d-(rock_dist[i][j]==(ori_dist[i][j]/d)),{i,j}});
		}
	} sort(wait.begin(),wait.end());
	auto set = [&]() {
		sq_dist[wait.back().s.f][wait.back().s.s] = wait.back().f; 
		sq.push(wait.back()); wait.pop_back();
	}; 
	if (wait.size()) {set();}
	// bfs from rotated squares
	while (sq.size()) {
		while (wait.size()&&(wait.back().f==sq.front().f)) {
			if (sq_dist[wait.back().s.f][wait.back().s.s]==INT_MAX) {set();}
			else {wait.pop_back();}
		}
		T cur = sq.front(); sq.pop();
		if (cur.f==0) {continue;}
		F0R(i,4) {
			pii x = {cur.s.f+dx[i], cur.s.s+dy[i]};
			if (x.f<0 || x.f>=n || x.s<0 || x.s>=n) {continue;}
			if (sq_dist[x.f][x.s]!=INT_MAX) {continue;}
			sq_dist[x.f][x.s] = cur.f-1;
			sq.push({cur.f-1,{x.f,x.s}});
		}
	} int ans = 0;
	F0R(i,n) {F0R(j,n) {ans += (sq_dist[i][j]!=INT_MAX);}}
	cout << ans << '\n';
}