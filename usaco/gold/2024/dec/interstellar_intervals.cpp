#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int mod = 1e9+7;
void add(int& a, int b) {a=(a+b)%mod;}
void sub(int& a, int b) {a=(a-b+mod)%mod;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<char> c(n+1);
    F0R(i,n) {cin >> c[i+1];}
    
    v<int> dp(n+1,0); dp[0] = 1;
    v<bool> bad1(n+1,0), bad2(n+1,0);
    int tot[2] = {1,0};
    v<int> iq2;
    int ptr = -1;

    FOR(i,1,n+1) {
        if (c[i]=='R') { // case R: one decreasing pointer
            ptr = i-2;
            for (int j=ptr;j>=0;j--) {
                if (bad1[j]) {break;}
                else if (!bad2[j]) {sub(tot[j&1],dp[j]);}
                bad1[j] = true;
            }
        } else if (c[i]=='B') { // case B: multiple decreasing pointers
            iq2.pb(i-1);
        } else { // case W: push from dp[i-1]
            add(dp[i],dp[i-1]);
        }

        add(dp[i],tot[i&1]); // add all same parity dp transitions
        add(tot[i&1],dp[i]);
        
        if (ptr>=0) { // update the single pointer
            if (!bad2[ptr]) {add(tot[ptr&1],dp[ptr]);}
            bad1[ptr--] = false;
        }

        v<int> nxt;
        for (int j : iq2) { // update the multiple pointers
            if (bad2[j]) {continue;}
            else if (!bad1[j]) {sub(tot[j&1],dp[j]);}
            bad2[j] = true;
            if (j-1>=0) {nxt.pb(j-1);}
        } iq2 = nxt;

        // if this isn't a valid transition, get rid of it
        if (bad1[i] || bad2[i]) {
            sub(tot[i&1],dp[i]);
        }
    } 
    cout << dp[n] << '\n';
}