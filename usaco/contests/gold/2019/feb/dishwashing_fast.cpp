#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("dishes.in","r",stdin);
    freopen("dishes.out","w",stdout);
    
    int n; cin >> n;
    v<int> p(n), to(n), ord(n);
    F0R(i,n) {
        cin >> p[i]; p[i]--;
        ord[p[i]] = i;
    }
    int mn = n;
    for (int i=n-1;i>=0;i--) {
        to[ord[i]] = (mn<ord[i] ? mn : -1);
        mn = min(mn,ord[i]);
    }

    v<stack<int>> s(n);
    int ptr = 0, sz = 0, mx = -1, ans = n;
    F0R(i,n) {
        if (p[i]<mx) {ans = i; break;} // have we already removed a larger dish (if so, it's impossible)

        if (to[i]==-1) { // side case: create new pile
            ord[i] = sz;
            s[sz++].push(p[i]);
        } else {
            int add = ord[to[i]]; ord[i] = add; // find pile it must be added to
            if (s[add].top()<p[i]) { // if we must remove a dish from the stack
                ptr = add; // then we remove all stacks before it as well
                while (s[ptr].top()<p[i]) {
                    mx = s[ptr].top(); // update max dish removed
                    s[ptr].pop();
                }
            }
            s[add].push(p[i]);
        }
    } cout << ans << '\n';
}