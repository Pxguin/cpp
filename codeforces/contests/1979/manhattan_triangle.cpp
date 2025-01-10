#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

struct Point {
	int x; int y; int id;
	Point(int x, int y, int id) : x(x), y(y), id(id) {};
	bool operator<(const Point& p2) {return x<p2.x;}
};

v<v<Point>> neg(400001), pos(400001); // +-1; slopes!

void solve() {
	int n, d; cin >> n >> d;
	int d2 = d/2;

	v<Point> p;
	set<int> posy, negy;
	F0R(i,n) {
		int x1, y1; cin >> x1 >> y1;

		p.pb(Point(x1,y1,i));
		posy.insert(p[i].y-p[i].x + 200000); // group by y-intercept of lines
		negy.insert(p[i].y+p[i].x + 200000); 
		neg[p[i].y+p[i].x + 200000].pb(p[i]);
		pos[p[i].y-p[i].x + 200000].pb(p[i]);
	}
	
	for (int i : posy) {sort(all(pos[i]));}
	for (int i : negy) {sort(all(neg[i]));}

	int a = 0, b = 0, c = 0;
	
	auto check = [&](int t, set<int>& p, v<v<Point>>& pts) {
		for (int i : p) {
			for (Point p1 : pts[i]) {
				int x1 = p1.x, x2 = x1+d2;
				auto p2 = lower_bound(all(pts[i]),Point(x2,0,0));

				if (p2!=pts[i].end() && p2->x==x2) { // does a valid second point exist on the line?
					int b1 = x2, b2 = x2+d2, t1 = x1-d2, t2 = x1;
					if (t) { // boring casework for finding the other two parallel segments
						swap(b1,t1); swap(b2,t2);
					}

					if (i >= d) { // bottom parallel line
						auto p3 = lower_bound(all(pts[i-d]),Point(b1,0,0)); // search if a point is in that segment
						if (p3!=pts[i-d].end() && p3->x<=b2) {
							a = p1.id+1; b = p2->id+1; c = p3->id+1;
						}
					} 
					if (i <= 400000-d) { // top line segment
						auto p3 = lower_bound(all(pts[i+d]),Point(t1,0,0));
						if (p3!=pts[i+d].end() && p3->x<=t2) {
							a = p1.id+1; b = p2->id+1; c = p3->id+1;
						}
					}
				}
			}
		}
	};
	check(0,posy,pos);
	check(1,negy,neg);

	// clear slopes
	for (int i : posy) {pos[i].clear();}
	for (int i : negy) {neg[i].clear();}

	cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}