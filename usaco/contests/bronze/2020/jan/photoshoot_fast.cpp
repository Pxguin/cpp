#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);

    const int MAX_N = 1e3;
    int n; cin >> n;
    int b[MAX_N];
    for (int i=0;i<n-1;i++) {cin >> b[i];}

    int perm[MAX_N];
    perm[0] = 1;
    int d1 = 0, d2 = n;
    
    for (int i=1;i<n;i++) { // calculate for a_1=1
        perm[i] = b[i-1]-perm[i-1];
        if (i%2) {chmin(d2,perm[i]-1);} // when does min(a_i)=1
        else {chmax(d1,1-perm[i]);} // there are two candidates
    }

    int p[MAX_N];
    auto check = [&](int d) { // check for a specific value of a_1
        bool used[MAX_N+1] = {false};
        p[0] = perm[0]+d;
        for (int i=1;i<n;i++) {
            int nxt = (i%2 ? perm[i]-d : perm[i]+d);
            if (used[nxt] || nxt<=0 || nxt>n) {return false;}
            used[nxt] = true; p[i] = nxt;
        } return true;
    };
    
    if (!check(min(d1,d2))) {check(max(d1,d2));} // check both candidates

    cout << p[0];
    for (int i=1;i<n;i++) {
        cout << ' ' << p[i];
    }
}