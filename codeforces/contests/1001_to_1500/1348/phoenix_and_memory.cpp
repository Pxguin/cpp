#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vec<int> l(n), r(n);
    vec<vec<int>> start(n);
    
    for (int i=0;i<n;i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
        start[l[i]].pb(i);
    }
    priority_queue<pii,vec<pii>,greater<pii>> todo;
    vec<int> ord(n);
    for (int i=0;i<n;i++) { // find one ordering
        for (int x : start[i]) {todo.push({r[x],x});}
        ord[todo.top().s] = i;
        start[i] = {todo.top().s};
        todo.pop();
    }

    pii swaps = {-1,-1};
    set<int> active;
    for (int i=0;i<n;i++) { // see if any two can be swapped
        int id = start[i][0]; // iterate in increasing order of label
        while (todo.size() && todo.top().f<i) {active.erase(todo.top().s); todo.pop();} // delete labels that can't swap with this label
        if (active.size() && *active.rbegin()>=l[id]) { // see if there's a label that this label can swap with
            swaps.f = start[*active.rbegin()][0];
            swaps.s = id;
        }
        todo.push({r[id],i});
        active.insert(i);
    }
    if (swaps.f==-1) {
        cout<<"YES\n";
        for (int i=0;i<n;i++) {cout << ord[i]+1 << ' ';}
    } else {
        cout << "NO\n";
        for (int i=0;i<n;i++) {cout << ord[i]+1 << ' ';} cout << '\n';
        swap(ord[swaps.f],ord[swaps.s]);
        for (int i=0;i<n;i++) {cout << ord[i]+1 << ' ';}
    }
}