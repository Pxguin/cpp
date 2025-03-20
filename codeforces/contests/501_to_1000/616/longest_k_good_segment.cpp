#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define chmax(a, b) a = max(a,b)

const int MAX_A = 1e6+1;
int freq[MAX_A] = {0};
int a[MAX_A];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, k; cin >> n >> k;
    for (int i=0;i<n;i++) {cin >> a[i];}

    pair<int,pii> ans = {0,{0,0}};
    for (int l=0,r=-1,distinct=0;l<n;l++) {
        while (r<n-1 && distinct<=k) {
            r++;
            if (++freq[a[r]]==1) {distinct++;}
        }
        if (distinct>k) {chmax(ans,mp(r-l-1,mp(l,r-1)));}
        else {chmax(ans,mp(r-l,mp(l,r)));}

        if (--freq[a[l]]==0) {distinct--;}
    }
    cout << ans.s.f+1 << ' ' << ans.s.s+1 << '\n';
}