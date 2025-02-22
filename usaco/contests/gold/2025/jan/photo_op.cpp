#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 3e5+2, MAX_C = 1e6+1;
int to[MAX_C+1];
v<int> stmax(4*MAX_N,0), stmin(4*MAX_N,INT_MAX);
int n;

void add(int idx, int val, int l=0, int r=n+1, int cur=1) {
	if (l==r) {stmin[cur] = stmax[cur] = val;}
	else {
		int m = (l+r)/2;
		if (idx<=m) {add(idx,val,l,m,2*cur);}
		else {add(idx,val,m+1,r,2*cur+1);}
		stmin[cur] = min(stmin[2*cur],stmin[2*cur+1]);
        stmax[cur] = max(stmax[2*cur],stmax[2*cur+1]);
	}
}
int get_min(int l, int r, int tl=0, int tr=n+1, int cur=1) {
	if (l>r) {return INT_MAX;}
	if (l==tl&&r==tr) {return stmin[cur];}
	int m = (tl+tr)/2;
	return min(get_min(l,min(r,m),tl,m,2*cur),get_min(max(l,m+1),r,m+1,tr,2*cur+1));
}
int get_max(int l, int r, int tl=0, int tr=n+1, int cur=1) {
    if (l>r) {return 0;}
	if (l==tl&&r==tr) {return stmax[cur];}
	int m = (tl+tr)/2;
	return max(get_max(l,min(r,m),tl,m,2*cur),get_max(max(l,m+1),r,m+1,tr,2*cur+1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> n >> t;
    ll x, y; cin >> x >> y;

    int in = sqrt(x*x+y*y); // initial distance when t=0
    multiset<int> d; // stores all candidate distances (take the min to get the answer)
    v<ll> dist(n+2,in);

    v<pair<ll,pii>> photo(n+2);
    v<int> xcoords = {0,MAX_C}; // two dummy segments at (0,0) and (inf,inf)
    F0R(i,n) { // coordinate compression for segment tree
        cin >> photo[i+2].f >> photo[i+2].s.f >> photo[i+2].s.s;
        xcoords.pb(photo[i+2].s.f);
    }
    sort(all(xcoords));
    F0R(i,n+2) {to[xcoords[i]] = i;}
    add(0,0); add(n+1,MAX_C);

    set<pii> tot;
    pii close = {0,MAX_C};

    auto dist_to_y = [&](ll pos, ll end1, ll end2)->int { // given a point on x-axis and two candidate y-axis points, find min distance from X to Y
        if (end1<=y && y<=end2) {
            return sqrt(pos*pos+y*y);
        }
        return min(sqrt(pos*pos+end1*end1)+abs(y-end1),
                        sqrt(pos*pos+end2*end2)+abs(y-end2));
    };

    auto recalc = [&](int i) { // is this region bad
        d.erase(d.find(dist[i]));

        ll s1 = (get_max(0,to[photo[i].s.f]-(photo[i].s.f<x))); // max y for all segments on left
        ll s2 = (get_min(to[photo[i].s.f]+(photo[i].s.f>x),n+1)); // min y for all segments on right

        if (s1>s2) { // if it's uncrossable then remove it
            tot.erase({photo[i].s.f,i});
            return true;
        } else { // otherwise, recalc distance
            dist[i] = abs(x-photo[i].s.f);
            d.insert(dist[i] += dist_to_y(photo[i].s.f,s1,s2));
        }
        return false;
    };
    
    cout << in << '\n'; // t=0
    ll s1 = photo[2].f, x1 = photo[2].s.f, y1 = photo[2].s.s;
    for (int time=1,cnt=2;time<t;time++) {
        while (s1<=time) { // process all cows at this current time
            tot.insert({x1,cnt});
            auto it = tot.find({x1,cnt});

            if (x1<x) {chmax(close.f,y1);} // this stores the region that X is in (side case)
            else {chmin(close.s,y1);}
            add(to[x1],y1); // add this new segment to segtree

            while (it!=tot.begin()) { // delete regions to the left while this segment blocks them
                if (!recalc(prev(it)->s)) {break;}
                it = tot.find({x1,cnt});
            }
            
            while (it!=prev(tot.end())) { // same thing for the right side
                if (!recalc(next(it)->s)) {break;}
                it = tot.find({x1,cnt});
            }
            
            d.insert(dist[cnt]);
            recalc(cnt); // calc distance for this new segment

            if (++cnt<n+2) { // transition to the next cow
                s1 = photo[cnt].f, x1 = photo[cnt].s.f, y1 = photo[cnt].s.s;
            } else {s1 = INT_MAX;}
        }
        int ans = INT_MAX;
        if (d.size()) {ans = *d.begin();} // take minimum distance
        if (close.f<=close.s) {chmin(ans,dist_to_y(x,close.f,close.s));}
        cout << ans << '\n';
        
    }
}