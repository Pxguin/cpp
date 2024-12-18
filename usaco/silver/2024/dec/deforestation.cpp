#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using T = pair<pii,int>;

void solve() {
    int n, k; cin >> n >> k;
    v<int> x(n);
    v<pii> q(k);
    v<int> t(k), c(k,0);
    F0R(i,n) {cin >> x[i];}
    F0R(i,k) {cin >> q[i].f >> q[i].s >> t[i];}

    v<T> events;
    F0R(i,n) {events.pb({{x[i],1},0});}
    F0R(i,k) {
        events.pb({{q[i].f,0},i});
        events.pb({{q[i].s,2},i});
    } sort(all(events));

    int cut = 0;
    multiset<int> mn;
    mn.insert(INT_MAX);

    Tree<pii> os;
    F0R(i,events.size()) { // calc max trees that can be cut down in each range
        auto[z,idx] = events[i];
        auto[pos,type] = z;
        if (type==1) {os.insert({pos,idx});}
        else if (type==2) {
            t[idx] = os.size()-os.order_of_key({q[idx].f,-1})-t[idx];
        }
    }

    F0R(i,events.size()) {
        auto[z,idx] = events[i];
        auto[pos,type] = z;

        if (type==0) { // start
            c[idx] = t[idx]+cut;
            mn.insert(c[idx]);
        } else if (type==1) { // tree
            if (*mn.begin()>=cut+1) {cut++;}
        } else {mn.erase(mn.find(c[idx]));} // end
    } cout << cut << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}