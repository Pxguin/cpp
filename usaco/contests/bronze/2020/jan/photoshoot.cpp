#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);

    const int MAX_N = 1e3;
    int n; cin >> n;
    int b[MAX_N];
    for (int i=0;i<n-1;i++) {cin >> b[i];}

    for (int i=1;i<=n;i++) { // test all values of a_0
        bool used[MAX_N+1] = {false};
        int perm[MAX_N];
        perm[0] = i;
        bool fail = false;
        
        for (int i=0;i<n-1;i++) {
            int nxt_cow = b[i]-perm[i]; // find next cow based on previous cow and b_i
            if (nxt_cow>=1 && nxt_cow<=n && !used[nxt_cow]) { // is the next cow valid
                used[nxt_cow] = true; // if so then update arrays
                perm[i+1] = nxt_cow;
            } else {fail = true;} // otherwise this value of a_0 fails
        }
        if (!fail) {
            cout << perm[0];
            for (int i=0;i<n-1;i++) {cout << ' ' << perm[i+1];}
            break;
        }
    }
}