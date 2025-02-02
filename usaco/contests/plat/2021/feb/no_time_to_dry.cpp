#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    v<int> a(n);
    F0R(i,n) {
        cin >> a[i];
    }
    v<int> stroke(n);
    iota(all(stroke),0);

    stack<int> s;
    v<int> range(n,-1), range_b(n,-1);
    for (int i=n-1;i>=0;i--) { // find set R
        while (s.size() && a[s.top()]>a[i]) {s.pop();}
        if (s.size() && a[s.top()]==a[i]) {
            stroke[i] = stroke[s.top()];
            if (i+1!=s.top()) { // find set S
                range[i+1] = s.top();
                range_b[s.top()] = i+1;
            }
            stroke[s.top()] = -1;
        }
        s.push(i);
    }

    v<int> active(n+1,0), start(n+1,0), nonvisible(n+1,0);
    F0R(i,n) { // calculate num segments intersecting each query segment
        if (stroke[i]!=-1) {
            start[i]++;
            active[i]++; active[stroke[i]+1]--;
        }
        start[i+1] += start[i];
        active[i+1] += active[i];
    }
    v<pair<pii,int>> qs(q);
    F0R(i,q) {
        cin >> qs[i].f.s >> qs[i].f.f; 
        qs[i].f.f--; qs[i].f.s--;
        qs[i].s = i;
    }
    sort(all(qs),greater<>());

    Tree<int> cur;
    queue<int> q1;
    v<int> ans(q);
    F0R(i,n) { // find num segments invisible for each query
        if (range_b[i]!=-1) {
            cur.erase(range_b[i]);
        }
        if (range[i]!=-1) {
            cur.insert(i);
        }
        while (qs.size() && qs.back().f.f==i) {
            auto [r,l] = qs.back().f;
            ans[qs.back().s] = active[l]+start[r]-start[l]-cur.order_of_key(l+1);
            qs.pop_back();
        }
    }
    F0R(i,q) {cout << ans[i] << '\n';}
}