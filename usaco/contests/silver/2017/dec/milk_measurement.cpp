#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    
    int n, g; cin >> n >> g;
    map<int,int> rate, freq;

    rate[100001] = g;
    freq[g] = n+1;
    int ans = 0;
    vec<pair<int,pii>> events(n);
    multiset<int> cows;

    for (int i=0;i<n+1;i++) {cows.insert(g);}
    for (int i=0;i<n;i++) {
        cin >> events[i].f >> events[i].s.f >> events[i].s.s;
        rate[events[i].s.f] = g;
    }
    sort(all(events));
    for (int i=0;i<n;i++) {
        auto[cow,delta] = events[i].s;

        int r = rate[cow];
        int c1 = freq[r], mx = *cows.rbegin();

        if (delta>0) {
            if (r!=mx && r+delta>=mx) {ans++;}
            else if (r==mx && c1>1) {ans++;}
        } else {
            int smx = *next(cows.rbegin());
            if (r==mx && r+delta<=smx) {ans++;}
            else if (r==mx && c1>1) {ans++;}
        }

        cows.erase(cows.find(r));
        freq[r]--;
        rate[cow] += delta;
        cows.insert(r+delta);
        freq[r+delta]++;
    }
    cout << ans << '\n';
}