#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

struct Frog {
    ll sz, pos, id, cnt=0;
    Frog() {};
};

int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int m; cin >> n >> m;
    vec<ll> segtree(4*n+1,0);
    vec<Frog> frogs(n);
    vec<ll> cnt(n,0), sz(n), pos(n);

    F0R(i,n) {cin >> frogs[i].pos >> frogs[i].sz; frogs[i].id = i;}
    sort(all(frogs),[&](const Frog& x, const Frog&y) {return x.pos<y.pos;}); // sort by position

    function<int(int,int,int)> build = [&](int cur, int l, int r) { // build segtree
        if (l==r) {segtree[cur] = frogs[l-1].sz+frogs[l-1].pos;}
        else {
            int m = (l+r)/2;
            segtree[cur] = max(build(2*cur,l,m),build(2*cur+1,m+1,r));
        } return segtree[cur];
    };

    multiset<pii> uneaten;
    auto eat = [&](int i, int c, int sze) { // frog eats a mosquito
        frogs[i].sz += sze;
        segtree[c] += sze;
        frogs[i].cnt++;
    };

    function<void(int,int,int,int,int)> upd = [&](int x, int sze, int cur, int l, int r) { // find first frog pos such that pos+tongue length >= mosquito pos
        if (l==r) {
            if (segtree[cur]>=x && frogs[l-1].pos<=x) {
                eat(l-1,cur,sze);

                auto it = uneaten.lower_bound({frogs[l-1].pos,-1});
                while (it!=uneaten.end() && it->f<=segtree[cur]) { // eat more uneaten mosquitoes while possible
                    eat(l-1,cur,it->s);
                    it = uneaten.erase(it);
                }
            } else {uneaten.insert({x,sze});} // this mosquito can't be eaten
        } else {
            int m = (l+r)/2;
            if (segtree[2*cur]>=x) {upd(x,sze,cur*2,l,m);}
            else {upd(x,sze,2*cur+1,m+1,r);}
            segtree[cur] = max(segtree[2*cur],segtree[2*cur+1]);
        }
    };

    build(1,1,n);
    F0R(i,m) {
        int x, z; cin >> x >> z;
        upd(x,z,1,1,n);
    }
    sort(all(frogs),[&](const Frog& x, const Frog& y) {return x.id<y.id;});
    F0R(i,n) {cout << frogs[i].cnt << ' ' << frogs[i].sz << '\n';}

}