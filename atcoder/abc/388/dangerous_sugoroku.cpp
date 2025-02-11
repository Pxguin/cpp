#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_B = 20;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, m, a, b; cin >> n >> m >> a >> b;
    ll last = 0;
    bool cur[MAX_B] = {false};
    cur[0] = true;

    F0R(i,m) {
        ll l, r; cin >> l >> r;
        bool nxt[MAX_B] = {false}, nxt2[MAX_B] = {false}; // store reachability of the 20 squares to the left/right of L_i/R_i respectively
        
        for (ll start = last+1; start <= last+MAX_B; start++) { // going from R_{i-1} to L_i
            if (!cur[start-last-1]) {continue;} // make sure we can reach the ith square to the right of R_{i-1}
            for (ll stop = max(start,l-MAX_B); stop < l; stop++) { // try to transition from that square to ith square to the left of L_i
                if ((stop-start)/a*b >= (stop-start)) { // is the transition possible
                    nxt[l-stop-1] = true;
                } 
            }
            if (start>r) {nxt2[start-r-1] = true;} // case 2: can skip over the whole range from the previous jump
        }

        for (ll start = l-MAX_B; start < l; start++) { // going from L_i to R_i
            if (!nxt[l-start-1]) {continue;} // make sure the square is reachable
            for (ll stop = a; stop <= b; stop++) { // make one jump to cross the range [L_i,R_i]
                if (stop+start>r) { // is the jump possible
                    nxt2[stop+start-r-1] = true;
                }
            }
        }
        last = r;
        F0R(j,MAX_B) {cur[j] = nxt2[j];}
    }
    bool ans = false;
    for (ll start = last+1; start <= min(n,last+MAX_B); start++) { // repeat of the above, but to check if we can reach square N
        if (cur[start-last-1] && (n-start)/a*b>=(n-start)) {
            ans = true;
        }
    } cout << (ans ? "Yes" : "No") << '\n';
}