#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n; cin >> n;
    set<pii> s;
    vec<int> a(2*n);
    F0R(i,2*n) {
        cin >> a[i];
        s.insert(make_pair(a[i],i));
    }
    vec<pii> ops;
    auto it2 = s.begin();

    F0R(i,2*n-1) {
        set<pii> rem = s;
        int mx = rem.rbegin()->f;
        ops.pb({it2->s,rem.rbegin()->s});
        rem.erase(prev(rem.end()));
        rem.erase(*it2);

        while (rem.size()) {
            ops.pb({rem.rbegin()->s,0});
            int other = rem.rbegin()->f;
            rem.erase(prev(rem.end()));

            auto it = rem.lower_bound({mx-other,-1});
            if (it==rem.end() || it->f!=mx-other) {break;}
            ops.back().s = it->s;
            rem.erase(it);
            mx = other;
        }
        if (rem.empty()) {break;}
        ops.clear();
        it2++;
    }
    if (ops.empty()) {cout << "NO\n";}
    else {
        cout << "YES\n";
        cout << a[ops[0].f]+a[ops[0].s] << '\n';
        F0R(i,n) {cout << a[ops[i].f] << ' ' << a[ops[i].s] << '\n';}
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}