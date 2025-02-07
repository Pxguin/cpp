#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 1000;
int a[MAX_N][MAX_N], sz[2*MAX_N], par[2*MAX_N];
bool swp[MAX_N][MAX_N];

void solve() {
    int n; cin >> n;
    F0R(i,2*n) {sz[i] = 1; par[i] = i;}
    F0R(i,n) {
        F0R(j,n) {
            cin >> a[i][j];
            swp[i][j] = false;
        }
    }
    auto get = [&](auto& get, int x)->int {return (par[x]==x ? x : par[x]=get(get,par[x]));};
    auto check = [&](int x, int y) {return get(get,x)==get(get,y);};
    auto merge = [&](int x, int y) {
        int a = get(get,x), b = get(get,y);
        if (a==b) {return;}
        if (sz[a]<sz[b]) {swap(a,b);}
        sz[a] += sz[b]; par[b] = a;
    };
    
    F0R(i,n) {
        F0R(j,n) {
            if (i<j) {
                if (a[i][j]>a[j][i]) { // if you have to swap this
                    if (!(check(i,j)||check(i+n,j+n))) { // if you can swap this
                        merge(i,j+n); merge(i+n,j); // swap them
                        swp[i][j] = swp[j][i] = true;
                    }
                } else if (a[i][j]<a[j][i]) { // if you don't want to swap them
                    if (!(check(i,j+n)||check(i+n,j))) { // if you can avoid swapping them
                        merge(i,j); merge(i+n,j+n); // don't swap them
                    } else {
                        swp[i][j] = swp[j][i] = true;
                    }
                }
            }
            cout << (swp[i][j] ? a[j][i] : a[i][j]) << ' ';
        } cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}