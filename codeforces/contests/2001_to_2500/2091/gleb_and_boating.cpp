#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

void solve() {
    int s, k; cin >> s >> k;
    vec<vec<int>> dp(k+1,vec<int>(k+1,-1));
    dp[k][0] = 0;

    int flip = 1, ans = 1;

    for (int i=k;i>1;i--) {
        vec<int> dp2(k+1,-1), dp3(k+1,-1);
        if (flip) { // simplify so that it is max to min transition
            for (int j=0;j<i;j++) {
                if (dp[i][j]==-1) {continue;}
                dp2[(s-dp[i][j])%i] = s-dp[i][j];
            }
            if (dp[i][s%i]!=-1) {ans = max(ans,i);} // is it possible to reach s from this power
        } else {dp2 = dp[i];}

        vec<vec<int>> add(2*i), del(2*i);
        for (int j=0;j<i;j++) { // find min and max modular residues achievable for mod i-1 (cap so that mx-mn<=i-1)
            if (dp2[j]==-1) {continue;}
            int mn = j%(i-1), mx;
            if (j+(i-1)*i <= dp2[j]) {mx = mn+i-2;} // if mx-mn=i-1
            else {mx = (dp2[j]-i)%(i-1);} // otherwise the limit on mx is capped by dp2[j] so determine it from that
            if (mx<mn) {mx += i-1;} // make sure mx>=mn

            int norm = j-(mn*i); // normalize for easy comparison
            add[mn].pb(norm); // events
            del[mx].pb(norm);
        }
        multiset<int> cur;
        for (int j=0;j<2*(i-1);j++) {
            for (int x : add[j]) {cur.insert(x);}
            if (cur.size()) {dp3[j%(i-1)] = *cur.begin()+j*i;} // select the smallest answer out of all available transitions
            for (int x : del[j]) {cur.erase(cur.find(x));}
        }

        if (flip) { // flip back again if necessary
            for (int j=0;j<i-1;j++) {
                if (dp3[j]==-1) {continue;}
                dp[i-1][(s-dp3[j])%(i-1)] = s-dp3[j];
            }
        } else {dp[i-1] = dp3;}
        flip ^= 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}