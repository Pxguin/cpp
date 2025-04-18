#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* to[2] = {};
    int cnt = 0;
};
void add(Trie* rt, int x) {
    Trie* cur = rt;
    for (int i=30;i>=0;i--) {
        bool b = (1<<i)&x;
        if (cur->to[b]==NULL) {
            cur->to[b] = new Trie;
        }
        cur->to[b]->cnt++;
        cur = cur->to[b];
    }
}
void remove(Trie* rt, int x) {
    Trie* cur = rt;
    for (int i=30;i>=0;i--) {
        bool b = (1<<i)&x;
        cur->to[b]->cnt--;
        cur = cur->to[b];
    }
}
int query(Trie* rt, int x) {
    Trie* cur = rt;
    int res = 0;
    for (int i=30;i>=0;i--) {
        bool b = (1<<i)&x;
        if (cur->to[!b]!=NULL && cur->to[!b]->cnt) {
            res ^= (1<<i);
            cur = cur->to[!b];
        } else {
            cur = cur->to[b];
        }
    } return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    Trie tr;
    int ans = INT_MAX;
    for (int i=0,l=0;i<n;i++) {
        cin >> a[i];
        add(&tr,a[i]); // add current index into window
        while (l<=i && query(&tr,a[i])>=k) { // advance left pointer while possible
            ans = min(ans,i-l+1);
            remove(&tr,a[l++]); // remove left from the window
        }
    }
    cout << (ans==INT_MAX ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}