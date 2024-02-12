#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

struct Event {
	int t, x, y;
	pair<int,int> pos;

	bool operator<(const Event &z) {return t < z.t;}
	Event(int time, int xp, int yp, pair<int,int> pos1) : t(time), x(xp), y(yp), pos(pos1) {}
};

void dfs(int cur, int par, vector<bool>& vis, vector<vector<int>>& stop, vector<int>& ans) {
	vis[cur] = true;
	for (int i : stop[cur]) {
		if (vis[i]) {ans[cur] += ans[i];}
		else {dfs(i, cur, vis, stop, ans);}
	}
	ans[par] += ans[cur];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> north;
	vector<int> east;
	vector<pair<int,int>> cows;
	vector<char> dir;
	char d; int xpos, ypos;
	for (int i=0;i<n;i++) {
		cin >> d >> xpos >> ypos;
		if (d == 'E') {east.pb(i);}
		else {north.pb(i);}
		cows.eb(xpos,ypos);
		dir.pb(d);
	}
	vector<Event> events;
	vector<vector<int>> stop(n);
	vector<pair<int,int>> stopped(n,mp(-1,-1)) ;
	for (int i : north) {
		for (int j : east) {
			int dist_n = cows[j].s-cows[i].s;
			int dist_e = cows[i].f-cows[j].f;
			if (dist_n > 0 && dist_e > 0) {
				if (dist_n > dist_e) {
					events.eb(dist_n, j, i, mp(cows[j].s, cows[i].f));
				} else if (dist_e > dist_n) {
					events.eb(dist_e, i, j, mp(cows[j].s, cows[i].f));
				}
			}
		}
	}
	sort(events.begin(), events.end());
	vector<int> ans(n+1, 0);

	for (auto i : events) {
		int x = i.x; int y = i.y; pair<int,int> pos = i.pos;
		bool works = true;
		if (stopped[y].f != -1) {
			continue;
		} else if (stopped[x].s != -1) {
			works = (stopped[x].f >= pos.f && stopped[x].s >= pos.s);
		}
		if (works) {
			stopped[y] = pos;
			stop[x].pb(y);
			ans[x]++;
		}
	}
	vector<bool> vis(n, false);
	for (int i=0;i<n;i++) {
		if (!vis[i]) {dfs(i, n, vis, stop, ans);}
		cout << ans[i] << "\n";
	}
}
