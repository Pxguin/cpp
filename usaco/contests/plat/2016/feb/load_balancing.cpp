#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end() 
#define v vector

int n, m;
v<v<int>> x, rx;

void sweep(v<pii>& vec, v<v<int>>& x2) { // find max pos such that <= m cows in region
    v<int> y(n,0);
    int ptr = n-1, ctr = 0, ptr2 = 0, ctr2 = 0;
    F0R(i,n) {
        for (int p : x2[i]) { // answers for bottom left & top left
            if (p<=ptr) {ctr++;}
            if (p>=ptr2) {ctr2++;}
            y[p]++;
        }
        while (ptr>=0&&ctr>m) {ctr -= y[ptr--];}
        while (ptr2<n&&ctr2>m) {ctr2 -= y[ptr2++];}
        vec[i+1] = {ptr2,ptr+1}; // combine answers into one range (what range of H lines work for this V line)
    }
}

bool check() {
    v<pii> rl(n+1), rr(n+1);
    rl[0] = rr[0] = {0,n};
    sweep(rl,x); sweep(rr,rx); // calculate for left and right sides
    reverse(all(rr));

    F0R(i,n+1) { // all possible V lines
        pii range = {max(rl[i].f,rr[i].f),min(rl[i].s,rr[i].s)}; // if nonempty range intersection then it's ok
        if (range.f<=range.s) {return true;}
    } return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);

    cin >> n;
    x.resize(n); rx.resize(n);
    v<pii> p(n);
    F0R(i,n) {cin >> p[i].f >> p[i].s;}

    auto compress = [&]() {
        sort(all(p));
        int last = p[0].f; p[0].f = 0;
        FOR(i,1,n) {
            if (last==p[i].f) {p[i].f=p[i-1].f;}
            else {
                last = p[i].f;
                p[i].f = p[i-1].f+1;
            }
        } F0R(i,n) {swap(p[i].f,p[i].s);}
    };
    compress(); compress(); // coordinate compression o(nlog^2n)->o(nlogn)
    F0R(i,n) {x[p[i].f].pb(p[i].s);} // group points by x coord
    F0R(i,n) {rx[n-i-1]=x[i];} // reverse x

    int l = 1, h = n, ans = n;
    while (l <= h) {
        m = (l+h)/2;
        if (check()) {h = m-1; ans = m;}
        else {l = m+1;}
    } cout << ans << '\n';
}