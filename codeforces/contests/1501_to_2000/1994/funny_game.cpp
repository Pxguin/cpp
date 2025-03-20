#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

int freq[2001];

void solve() {
    int n; cin >> n;
    vec<int> a(n);
    F0R(i,n) {cin >> a[i];}

    vec<bool> del(n,false);
    vec<pii> ans;
    for (int i=n-1;i;i--) {
        memset(freq,0,sizeof(freq));
        F0R(j,n) {
            if (!del[j]) {
                int m = a[j]%i;
                if (freq[m]!=0) {
                    ans.pb({j+1,freq[m]});
                    del[j] = true;
                    break;
                }
                freq[m] = j+1;
            }
        }
    } reverse(all(ans));
    cout << "YES\n";
    F0R(i,n-1) {cout << ans[i].f << ' ' << ans[i].s << '\n';}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}

}