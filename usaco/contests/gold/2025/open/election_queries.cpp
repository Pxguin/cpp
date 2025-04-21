#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

int main() {
    int n, q; cin >> n >> q;
    vec<int> a(n), freq(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        freq[--a[i]]++;
    }
    set<int> todo; // set of all frequencies
    vec<set<int>> tot(n+1);
    for (int i=0;i<n;i++) {
        tot[freq[i]].insert(i); // tot[f]: stores all indices that have frequency f
        if (freq[i]) {todo.insert(freq[i]);}
    }

    while (q--) {
        int x, b; cin >> x >> b; x--; b--;
        tot[freq[a[x]]].erase(a[x]); tot[freq[b]].erase(b);
        if (tot[freq[a[x]]].size()==0) {todo.erase(freq[a[x]]);}
        if (tot[freq[b]].size()==0) {todo.erase(freq[b]);}

        tot[--freq[a[x]]].insert(a[x]); tot[++freq[b]].insert(b);
        if (freq[a[x]]) {todo.insert(freq[a[x]]);}
        if (freq[b]) {todo.insert(freq[b]);}
        a[x] = b; // change all the frequencies and update the arrays

        int mn = 1e9, mx = -1e9, ans = 0;
        auto it2 = todo.rbegin();
        for (auto it=todo.begin();it!=todo.end();it++) { // two pointers
            while (it2!=todo.rend() && *it+*it2>=*todo.rbegin()) { // decrease right ptr while sum >= max(freq)
                chmin(mn,*tot[*it2].begin()); // get minimum possible index that can be a leader right now
                chmax(mx,*tot[*it2].rbegin()); // get maximum possible
                it2++;
            }
            chmax(ans,mx-*tot[*it].begin()); // get max possible diversity
            chmax(ans,*tot[*it].rbegin()-mn);
        } cout << ans << '\n';
    }
}