#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
 
map<pair<int,int>,vector<int>> forw;
pair<int,int> cur = mp(0,0);
int l, r, n;
vector<pair<int,int>> pos;
 
bool check() {
    if (forw.count(cur) && (forw[cur].front() < l || forw[cur].back() >= r)) {return true;}
 
    pair<int,int> start = pos[r];
    pair<int,int> stop = pos[l-1];
    pair<int,int> disp = mp(stop.f+start.f-cur.f, stop.s+start.s-cur.s);
    if (forw.count(disp)) {
        int idx = lb(forw[disp].begin(), forw[disp].end(), l) - forw[disp].begin();
        if (idx != forw[disp].size() && forw[disp][idx] <= r) {return true;}
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    string seq; cin >> seq;
 
    pos.pb(cur);
    for (char z : seq) {
        cur.s += (z == 'U')-(z == 'D');
        cur.f += (z == 'R')-(z == 'L');
        pos.pb(cur);
    }
    for (int i=0;i<n+1;i++) {
        forw[pos[i]].pb(i);
    }
    while (q--) {
        cin >> cur.f >> cur.s >> l >> r;
        cout << (check() ? "YES" : "NO") << "\n";
    }
}