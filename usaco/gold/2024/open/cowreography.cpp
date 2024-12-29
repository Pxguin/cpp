#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    char c;
    v<bool> s(n), t(n);
    F0R(i,n) {cin >> c; s[i]=(c=='1');}
    F0R(i,n) {cin >> c; t[i]=(c=='1');}
    int state = -1;

    deque<pii> active;
    ll ans = 0;
    F0R(i,n) {
        if (s[i]!=t[i]) {
            if (state==-1) {state=s[i]; i--; continue;} // new component
            while (active.size()&&active.front().f<i) { // increment
                pii x = active.front(); active.pop_front();
                ans += x.s;
                active.push_back({x.f+k,x.s});
            }
            if (s[i]==state) { // start index
                if (active.size() && active.front().f==i) {active.front().s++;}
                else {active.push_front({i,1});}
            } else { // end index
                active.front().s--;
                if (active.front().s==0) {active.pop_front();}
            }
        }
        if (active.empty()) {state = -1;} // done with current component
    } cout << ans << '\n';
}