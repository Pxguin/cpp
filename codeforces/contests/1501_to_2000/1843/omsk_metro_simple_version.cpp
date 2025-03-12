#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

void solve() {
    int n; cin >> n;
    vec<pii> mx(n+1,{1,1}), mn(n+1,{0,0});

    int c = 1;
    while (n--) {
        char t; cin >> t;
        if (t=='+') {
            int a, b; cin >> a >> b; a--;
            mx[c] = mx[a]; mn[c] = mn[a];

            if ((mx[c].s+=b)<=0) {mx[c].s = 0;} // use kadane's alg
            else {chmax(mx[c].f,mx[c].s);}
            if ((mn[c].s+=b)>=0) {mn[c].s = 0;}
            else {chmin(mn[c].f,mn[c].s);}
            
            c++;
        } else {
            int a, b, k; cin >> a >> b >> k;
            b--;
            cout << (mn[b].f<=k && mx[b].f>=k ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}