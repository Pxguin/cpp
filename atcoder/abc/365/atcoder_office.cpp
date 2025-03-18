#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

const int MAX_N = 2e5, MAX_M = 2e5, K = 450;
vec<pii> t[MAX_N], e;
vec<int> queries[MAX_N];

int single(int a, int b) {
    int res = 0;
    for (int i=0,ptr=0;i<t[a].size();i++) {
        while (ptr<t[b].size() && t[b][ptr].s<=t[a][i].s) { // two pointers to calculate intersection manually
            res += max(0,min(t[b][ptr].s,t[a][i].s)-max(t[b][ptr].f,t[a][i].f));
            ptr++;
        }
        if (ptr<t[b].size()) {
            res += max(0,min(t[b][ptr].s,t[a][i].s)-max(t[b][ptr].f,t[a][i].f));
        }
    } return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int tm, p; cin >> tm >> p;
        p--;
        if (t[p].size()==0 || t[p].back().s!=-1) {
            t[p].pb({tm,-1});
            e.pb({-tm,p});
        } else {
            t[p].back().s = tm;
            e.pb({tm,p});
        }
    }

    for (int i=0;i<n;i++) {
        if (t[i].size()>K) {
            queries[i].resize(n);
            int ps = 0, ptr = 0; // store prefix sums
            for (int j=0;j<t[i].size();j++) {
                int last = t[i][j].f;
                while (ptr<e.size() && abs(e[ptr].f)<=t[i][j].s) { // calculate intersection to all other sets with prefix sums
                    ps += max(0,abs(e[ptr].f)-last);
                    last = max(last,abs(e[ptr].f));

                    queries[i][e[ptr].s] += (e[ptr].f<=0 ? -1 : 1) * ps; 
                    ptr++;
                }
            }
            while (ptr<e.size()) { // process remaining ranges
                queries[i][e[ptr].s] += (e[ptr].f<=0 ? -1 : 1) * ps;
                ptr++;
            }
        }
    }
    
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (t[a].size()<t[b].size()) {swap(a,b);}
        if (t[a].size()>K) {cout << queries[a][b] << '\n';}
        else {cout << single(a,b) << '\n';}
    }
}