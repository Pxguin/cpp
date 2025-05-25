#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

const int MAX_N = 3e5, REPS = 25;

struct BIT {
    ll sum[MAX_N+1] = {0};
    void add(int i, ll a) {
        for (;i<=MAX_N;i+=(i&-i)) {sum[i] += a;}
    }
    ll get(int i) {
        ll res = 0;
        for (;i;i-=(i&-i)) {res += sum[i];}
        return res;
    }
};

ll hsh[REPS][2*MAX_N]; // hashes
int a[MAX_N+1];
BIT bits[REPS]; // fenwick trees
array<int,4> qu[MAX_N]; // queries

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
void pre() {
    for (int r=0;r<REPS;r++) {
        for (int i=0;i<2*MAX_N;i++) {
            hsh[r][i] = uniform_int_distribution<long long>(1,1e12)(gen);
        }
    }
}

void upd(int i, int x) { // change the value of a[i]
    for (int r=0;r<REPS;r++) { // update the fenwick trees with the new hash value
        bits[r].add(i,hsh[r][x]-hsh[r][a[i]]);
    } a[i] = x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    pre(); // assign all hashes

    map<int,int> u; // union of all values (for compression)

    int n, q; cin >> n >> q;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        u[a[i]] = 0;
    }

    for (int i=0;i<q;i++) { // get queries for compress
        cin >> qu[i][0] >> qu[i][1] >> qu[i][2];
        if (qu[i][0]==2) {cin >> qu[i][3];}
        else {u[qu[i][2]] = 0;}
    }

    for (auto it=next(u.begin());it!=u.end();it++) {u[it->f] = prev(it)->s+1;}
    for (int i=1;i<=n;i++) {a[i] = u[a[i]];} // do the compression
    for (int i=0;i<q;i++) { // update all queries and values
        if (qu[i][0]==1) {qu[i][2] = u[qu[i][2]];}
    }

    for (int r=0;r<REPS;r++) { // initialize BITs
        for (int i=1;i<=n;i++) {bits[r].add(i,hsh[r][a[i]]);}
    }

    for (int i=0;i<q;i++) {
        int t = qu[i][0];
        if (t==1) {
            int id = qu[i][1], x = qu[i][2];
            upd(id,x);
        } else {
            int l = qu[i][1], r = qu[i][2], k = qu[i][3];
            bool ans = true;
            for (int re=0;re<REPS;re++) {
                ans = (ans&&((bits[re].get(r)-bits[re].get(l-1))%k==0)); // sum is divisible by K for all trials
            } cout << (ans ? "YES" : "NO") << '\n';
        }
    }
}