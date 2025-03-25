#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

using T = pair<pii,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    const int K = 1e3;
    vec<vec<T>> blocks(K+1);
    F0R(i,n) {
        int x, y; cin >> x >> y;
        blocks[x/K].pb({{y,x},i+1}); // push into blocks of X
    }
    F0R(i,K+1) {
        if (i%2) { // sort by inc/dec Y
            sort(all(blocks[i]));
        } else {
            sort(all(blocks[i]),[&](const T& a, const T& b) {
                return (a.f.f==b.f.f ? a.f.s<b.f.s : a.f.f>b.f.f);
            });
        }
        for (T x : blocks[i]) {cout << x.s << ' ';} // order of traversal
    }
}