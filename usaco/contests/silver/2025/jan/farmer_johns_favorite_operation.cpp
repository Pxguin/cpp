#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<int> a(n);
    map<int,int> events;
    F0R(i,n) {
        cin >> a[i]; a[i] %= m;
    }
    ll time = 0, sum = 0, delta = 0, f2 = m/2, c2 = (m+1)/2;
    F0R(i,n) {
        sum += min(a[i],m-a[i]);

        if (a[i]==0) { // haha casework
            events[0]++;
            events[f2]--;
            events[c2]--;
        } else if (a[i]<=c2) {
            events[max(0LL,a[i]-f2)]--;
            events[a[i]] += 2;
            events[a[i]+f2]--;
            events[a[i]+c2]--;
        } else {
            events[0]++;
            events[a[i]-c2]--;
            events[a[i]-f2]--;
            events[a[i]] += 2;
        }
    }
    ll ans = sum;
    for (auto[t,d] : events) { // do some sweep line over breakpoints of abs value functions
        if (t>=m) {break;}
        sum += (t-time)*delta;
        time = t; delta += d;
        chmin(ans,sum);
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}