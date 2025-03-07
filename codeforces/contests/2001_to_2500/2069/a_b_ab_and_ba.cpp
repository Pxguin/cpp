#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    string s; cin >> s;
    int n = s.size();
    s += s.back();
    int a[2], ab[2];
    cin >> a[0] >> a[1] >> ab[0] >> ab[1];

    v<string> split[2];
    int last = 0;
    FOR(i,1,n+1) { // find splitting points in string, and sort by parity of length
        if (s[i]==s[i-1]) {
            int len = i-last;
            split[len%2].pb(s.substr(last,len));
            last = i;
        }
    }
    v<int> cnt[2];
    F0R(i,2) {cnt[i].assign(n+1,0);}

    F0R(i,split[0].size()) { // assign all the even length strings to their respective bins
        int len = split[0][i].size()/2;
        ab[split[0][i][0]=='B'] -= len;
        cnt[split[0][i][0]=='B'][len]++;
    }
    
    int x = 0, y = 1;
    if (ab[1]<0 && ab[0]>0) {swap(x,y);}
    if (ab[x]<0 && ab[y]>0) { // if one underflows but the other overflows, then balance them out starting with largest length strings
        for (int i=n;i;i--) {
            bool flag = false;

            F0R(j,cnt[x][i]) {
                a[0]--; a[1]--;
                int d = min(i-1,ab[y]);
                ab[x] += d+1; ab[y] -= d;
                if (ab[y]==0 || ab[x]>=0) {flag = true; break;}
            }
            if (flag) {break;}
        }
    }
    int tot = 0;
    F0R(i,split[1].size()) { // odd length strings are wild cards, so they can go anywhere
        int len = split[1][i].size()/2;
        a[split[1][i][0]=='B']--;
        tot += len;
    }
    if (ab[0]>0) { // fill in gaps while possible
        int d = min(ab[0],tot);
        tot -= d; ab[0] -= d;
    } ab[1] -= tot;


    a[0] = min(a[0],a[1]);
    if (ab[0]<0) {a[0] += ab[0];} // use one of each (a,b) to fill in missing ab and ba
    if (ab[1]<0) {a[0] += ab[1];}

    // check for non-negative totals
    cout << (a[0]>=0 ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}