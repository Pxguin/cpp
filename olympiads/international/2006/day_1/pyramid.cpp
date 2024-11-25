#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, a, b, c, d; cin >> m >> n >> a >> b >> c >> d;
	v<v<int>> g(n,v<int>(m));
	v<v<int>> ps(n+1,v<int>(m+1,0));
	v<v<pii>> mn(n,v<pii>(m));
	F0R(i,n) {
		F0R(j,m) {
			cin >> ps[i+1][j+1];
			g[i][j]=ps[i+1][j+1];
			ps[i+1][j+1] += ps[i+1][j]+ps[i][j+1]-ps[i][j];
		}
	}
	auto get = [&](int c1, int r1) {return ps[r1+d][c1+c]-ps[r1+d][c1]-ps[r1][c1+c]+ps[r1][c1];};
	auto get2 = [&](int r1, int c1) {return ps[r1+b][c1+a]-ps[r1+b][c1]-ps[r1][c1+a]+ps[r1][c1];};

	v<deque<int>> mq(m);
	auto push = [&](int idx, int pos) {
		while (mq[idx].size() && get(idx,pos)<get(idx,mq[idx].back())) {mq[idx].pop_back();}
		mq[idx].pb(pos);
	};
	FOR(col,1,(m-2)-c+2) { // initialize min query for each column over a window
		FOR(row,1,(b-2)-d+2) {
			push(col,row);
		}
	}

	F0R(row,n-b+1) {
		deque<int> q;
		FOR(col,1,m-2-c+2) { // min query for each column's min over a window, effectively 2d min query
			while (q.size() && get(col,mq[col].front())<get(q.back(),mq[q.back()].front())) {q.pop_back();}
			q.pb(col);
			if (col>=(a-2)-c+1) {
				int s = col-((a-2)-c+1);
				mn[row][s] = mp(q.front(),mq[q.front()].front());
				if (q.front()==s+1) {q.pop_front();}
			}
		}
		FOR(col,1,(m-2)-c+2) { // update column min queries (slide window)
			if (mq[col].front()==row+1) {mq[col].pop_front();}
			push(col,row+(b-2)-d+2);
		}
	}

	int ans = 0;
	pii a1, a2;
	F0R(i,n-b+1) { // the optimal answer is maximum of outside area minus inside area
		F0R(j,m-a+1) {
			int cand = get2(i,j)-get(mn[i][j].f,mn[i][j].s);
			if (cand>ans) {
				ans = cand;
				a1 = {j,i}; a2 = mn[i][j];
			}
		}
	}
	cout << a1.f+1 << ' ' << a1.s+1 << '\n';
	cout << a2.f+1 << ' ' << a2.s+1 << '\n';
}