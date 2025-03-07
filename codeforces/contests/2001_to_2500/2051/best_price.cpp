#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, k; cin >> n >> k;
    map<int,pii> ctr;
    F0R(i,n) { // A values
        int a; cin >> a;
        ctr[a].f++;
    }
    F0R(i,n) { // B values
        int b; cin >> b;
        ctr[b].s++;
    }
    int bad = 0, tot = n;
    ll ans = 0;
    for (auto [val,amt] : ctr) {
        if (bad<=k) {chmax(ans,(ll)val*tot);}
        auto [neg,stop] = amt;
        bad += neg-stop; // update # of people who leave negative reviews
        tot -= stop; // update # of people who will still buy a tree
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}