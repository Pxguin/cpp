#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 50000, l2d = 16, MAX_K = 5;
int dist[MAX_N][MAX_K][l2d][MAX_K];
int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k, o; cin >> k >> n >> m >> o;

    F0R(i,n) F0R(j,k) F0R(l,l2d) F0R(z,k) {dist[i][j][l][z] = INF;}
    F0R(i,m) {
        int a, b, t; cin >> a >> b >> t;
        dist[a/k][a%k][0][b%k] = t;
    }
    for(int p=1,p2=2;p<l2d;p++,p2*=2) { // bin jump
        F0R(i,n-p2) {
            F0R(start,k) F0R(mid,k) F0R(stop,k) {
                chmin(dist[i][start][p][stop],
                    dist[i][start][p-1][mid]+dist[i+p2/2][mid][p-1][stop]);
            }
        }
    }
    
    while (o--) {
        int a, b; cin >> a >> b;
        int d = b/k-a/k;

        v<int> ans(k,INF);

        ans[a%k] = 0;
        a /= k;

        for (int b=0,p=1;b<l2d;b++,p*=2) { // do queries
            if (d&(1<<b)) {
                v<int> nxt(k,INF);
                F0R(i,k) {
                    F0R(j,k) {
                        chmin(nxt[j],ans[i]+dist[a][i][b][j]);
                    }
                }
                ans = nxt;
                a += p;
            }
        }
        
        cout << (ans[b%k]==INF ? -1 : ans[b%k]) << '\n';
    }
}