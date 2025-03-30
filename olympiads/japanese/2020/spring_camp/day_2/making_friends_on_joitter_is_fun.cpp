#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

const int MAX_N = 1e5;
unordered_set<int> in[MAX_N], out[MAX_N], comp[MAX_N];
ll par[MAX_N], sz[MAX_N];
ll ans = 0;
queue<pair<int,int>> todo;

int get(int x) {return par[x]==x ? par[x] : par[x]=get(par[x]);}

void add(int x, int y) {
    if (out[x].count(y)) {return;} // side case: there already exists an edge between the two components

    out[x].insert(y); // add edge
    in[y].insert(x);
    
    if (out[y].count(x)) {todo.push({x,y});} // if there is a bidirectional edge, merge the components
}

int tot_sz(int x) {return comp[x].size()+in[x].size()+out[x].size();}

void merge(int a, int b) {
    a = get(a); b = get(b);
    if (a==b) {return;}

    ans -= comp[a].size()*sz[a]-sz[a]; // subtract the old answer for this comp;
    ans -= comp[b].size()*sz[b]-sz[b];

    if (tot_sz(a)<tot_sz(b)) {
        swap(a,b);
    }

    in[a].erase(b); out[a].erase(b); // erase the bidirectional edge between the comps;
    in[b].erase(a); out[b].erase(a);

    for (int x : out[b]) { // merge the in and out arrays;
        in[x].erase(b);
        add(a,x);
    }
    for (int x : in[b]) {
        out[x].erase(b);
        add(x,a);
    }

    for (int x : comp[b]) {comp[a].insert(x);} // the comp arrays;
    
    sz[a] += sz[b];
    ans += comp[a].size()*sz[a]-sz[a]; // and add back the new answer for this comp
    par[b] = a;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    F0R(i,MAX_N) {
        par[i] = i;
        sz[i] = 1;
        comp[i].insert(i);
    }
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        a--; b--;

        if (!comp[get(b)].count(a)) {ans += sz[get(b)];} // edge a->b, so add a to the comp set of b and upd ans
        comp[get(b)].insert(a);
        a = get(a); b = get(b);
        add(a,b); // finally add edge between component of a and component of b

        while (todo.size()) { // todo merge
            merge(get(todo.front().first),get(todo.front().second));
            todo.pop();
        }
        cout << ans << '\n';
    }
}
