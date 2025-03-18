#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 2e5, MAX_M = 2e5;
vec<int> ps[MAX_N], start[MAX_N], stop[MAX_N];

int isect(int a, int b, int i, int j) { // intersection of two segments
    return max(0,min(stop[a][i],stop[b][j])-max(start[a][i],start[b][j]));
}

int single(int a, int b) {
    int res = 0;
    for (int i=0,ptr=0;i<start[a].size();i++) { // two pointers to calculate intersection of sets
        int left = lower_bound(all(start[b]),start[a][i])-start[b].begin()-1;
        if (left!=start[b].size() && left!=-1) { // process a segment intersection on the left endpoint
            res += isect(a,b,i,left);
        }
        int right = upper_bound(all(stop[b]),stop[a][i])-stop[b].begin()-1;
        if (right!=stop[b].size() && right>left) { // quickly calculate the sum of all segments contained in this segment
            res += ps[b][right+1]-ps[b][left+1]; // with binary search and prefix sums
        }
        if (right>=left && ++right<stop[b].size()) { // process a segment intersection on the right endpoint
            res += isect(a,b,i,right);
        }
    } return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<n;i++) {ps[i].pb(0);}
    for (int i=0;i<m;i++) {
        int tm, p; cin >> tm >> p;
        p--;
        if (start[p].size()==stop[p].size()) {
            start[p].pb(tm);
        } else {
            stop[p].pb(tm);
            ps[p].pb(ps[p].back()+stop[p].back()-start[p].back());
        }
    }
    
    int q; cin >> q;
    map<pair<int,int>,int> precalc;
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (start[a].size()>start[b].size()) {swap(a,b);}
        if (!precalc.count({a,b})) {precalc[{a,b}] = single(a,b);} // memoize queries
        cout << precalc[{a,b}] << '\n';
    }
}