#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int P = 4213597;
int bell[12] = {1,2,5,15,52,203,877,4140,21147,115975,678570,4213597};
ll grp[P][12] = {0};
int nxt = 0, n;
ll a[12];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    F0R(i,n) {cin >> a[i];}
    queue<pair<int,pair<int,int>>> q; // group index, current index, num groups
    q.push({0,{0,0}});

    while (q.size()) {
        auto x = q.front(); q.pop();
        if (x.s.f==n) {continue;}

        grp[x.f][x.s.s] += a[x.s.f]; // extend current group
        q.push({x.f,{x.s.f+1,x.s.s+1}});

        F0R(i,x.s.s) { // extend current group
            nxt++;
            F0R(m,x.s.s) {grp[nxt][m] = grp[x.f][m];} // copy the existing group
            grp[nxt][i] += a[x.s.f]; // add the new element
            q.push({nxt,{x.s.f+1,x.s.s}});
        }
    }
    unordered_set<ll> s;
    F0R(i,bell[n-1]) { // get all possible xors
        F0R(j,n-1) {grp[i][n-1] ^= grp[i][j];}
        s.insert(grp[i][n-1]);
    } cout << s.size() << '\n';
}