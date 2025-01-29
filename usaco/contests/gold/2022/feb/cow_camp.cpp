#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t, k; cin >> t >> k;
    t--; // ignore sample case
    v<ld> prob(t+1);
    prob[0] = prob[t] = 1/pow(2,t);

    F0R(i,t-1) { // calculate probabilities
        prob[i+1] = prob[i]*(t-i)/(i+1);
    }

    int ptr = 0;
    ld lh = 0, rh = 0;
    F0R(i,t+1) {lh += prob[i]*i;}
    ld e = 0;

    while (k>0) {
        int l = 1, h = k, m = (l+h)/2, ans = k;
        while (l <= h) { // bin search to advance expected value
            ld t = (1-pow(rh,m))/(1-rh)*lh+pow(rh,m)*e;
            if (t>=ptr) {
                ans = m; h = m-1;
            } else {l = m+1;}
            m = (l+h)/2;
        }
        k -= ans;
        e = (1-pow(rh,ans))/(1-rh)*lh+pow(rh,ans)*e;
        while (ptr<=t && ptr<=e) { // update lh and rh
            lh -= prob[ptr]*ptr;
            rh += prob[ptr];
            ptr++;
        }
    } cout << fixed << setprecision(10) << e+1 << '\n';
}