#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n, q; cin >> n >> q;
    vec<int> w(n);
    F0R(i,n) {cin >> w[i];}

    set<pii> s;
    F0R(i,q) {
        int x; cin >> x;
        s.insert({x,i});
    }
    vec<int> ans(q,n);
    int xor_ = 0;
    for (int i=n-1;i>=0;i--) {
        for (int bit=30,mask=0;bit>=0;bit--) { // fix a suffix of the bitwise representation of w[i]
            mask ^= ((xor_&(1<<bit)) ^ (w[i]&(1<<bit)));
            if (w[i]&(1<<bit)) { // if this bit is set in weight,
                mask ^= (1<<bit); // then make it unset in xor^x
                for (auto it=s.upper_bound({mask,-1});it!=s.end()&&it->f<=(1<<bit)-1+mask;) { // and all bits before that can be anything
                    ans[it->s] = n-i-1; // so answer all queries satisfying that bit pattern
                    it = s.erase(it);
                }

                mask ^= (1<<bit);
            }
        }
        xor_ ^= w[i];
    }
    F0R(i,q) {cout << ans[i] << ' ';}
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}