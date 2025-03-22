#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n; cin >> n;

    ll pref = 0, b = 59;
    int rem = 3;
    ll ans[3];
    while (rem!=0) {
        ll lb = pref|(1LL<<b), ub = (1LL<<(b+1))-1+pref, llb = max(pref,1LL);
        b--;
        if (lb>n) {continue;}
        ub = min(ub,n);
        
        cout << "xor " << lb << ' ' << ub << endl;
        ll x; cin >> x;
        
        bool nxt = false;

        if (x&(1LL<<(b+1))) { // either 1 or 3 in this range
            ll y;
            if (x>n) {y = -2;} // test to see if it's 1 in this range
            else {
                cout << "xor " << x << ' ' << x << endl;
                cin >> y;
            }

            if (y==x) { // if so then we found one
                ans[--rem] = y;
                if (rem==1) { // is the other one in the other range
                    cout << "xor " << llb << ' ' << lb-1 << endl;
                    ll y; cin >> y;
                    ans[--rem] = y;
                }
            } else { // found nothing in the other range, so there must be 3 in this range
                nxt = true;
            }
        } else if (x>0) { // there are 2 in this range
            if (rem==3) { // if 3 remaining, the third number is in the other range
                cout << "xor " << llb << ' ' << lb-1 << endl;
                ll y; cin >> y;
                ans[--rem] = y;
            }
            nxt = true; // otherwise, can do nothing
        } else { // 0 numbers in this range
            if (rem==1) { // if 1 remaining, it's in the other range
                cout << "xor " << llb << ' ' << lb-1 << endl;
                ll y; cin >> y;
                ans[--rem] = y;
            }
        }
        if (nxt) {pref = lb;} // which subrange to go to
    }
    cout << "ans " << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}