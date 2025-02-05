#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n; cin >> n;
    v<pii> s;

    F0R(i,n) {
        ll a, b; cin >> a >> b;
        ll t = a, left = a;
        bool flag = false;

        while (!flag) {
            ll mx = left;
            while (s.size()&&s.back().f<t&&s.back().s!=b) { // either it disappears or we can merge it
                mx = t-s.back().f; // what's the size of the block left
                s.pop_back();
            }
            if (s.size() && s.back().s==b) {
                left = mx;
                t = s.back().f+left; // this is the new time that the block disappears
                s.pop_back();
            } else { // no more possible operations
                s.pb({t,b});
                flag = true;
            }
        }
        cout << s[0].f << ' '; // the maximum time until a block disappears
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}