#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    v<v<int>> col(n);
    F0R(i,n) {col[--a[i]].pb(i);}

    auto test = [&](int i, int j) {
        int ctr = 1, last = col[i][0];
        for (int k : col[i]) {
            if (k-last>j) {last = k; ctr++;}
        } return ctr;
    };

    int c = ceil(sqrt(n));
    v<v<pii>> events(n+1);
    F0R(i,n) {
        if (col[i].empty()) {continue;}

        int sz = col[i].back()-col[i][0];
        FOR(j,1,min(c+1,sz+1)) { // size
            events[j].pb({test(i,j),i});
        }
        FOR(j,1,min(c+1,(int)col[i].size()+1)) { // number
            int l = 1, h = sz, m = (l+h)/2, ans;
            while (l<=h) {
                int res = test(i,m);
                if (res<=j) {h = m-1; ans = m;}
                else {l = m+1;}
                m = (l+h)/2;
            }
            events[ans].pb({test(i,ans),i});
        }
    }

    int ans = n;
    v<int> mn(n);
    F0R(i,n) {mn[i] = col[i].size();}
    FOR(i,1,n+1) { // update answer
        for (pii x : events[i]) {
            ans -= mn[x.s]-x.f;
            mn[x.s] = x.f;
        } cout << ans << '\n';
    }
}