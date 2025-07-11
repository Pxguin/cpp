#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)

const int N = 300, K = 4;
int dist1[K][N], distn[K][N], dist2[N][N];
int wt[N][N], w2[N][N];

int a[N*N], b[N*N], w[N*N], ans[N*N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {dist2[i][j] = wt[i][j] = ans[i*N+j] = 1e9;}
        for (int j=0;j<K;j++) {dist1[j][i] = distn[j][i] = 1e9;}
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> w2[i][j];
        }
    }
    for (int i=0;i<n*n;i++) {
        cin >> a[i] >> b[i];
    }
    for (int i=n*n-1;i>=0;i--) {
        
        for (int j=0;j<n;j++) { // calculate answer
            chmin(ans[i],dist1[k/2 -1][j]+distn[(k+1)/2 -1][j]);
        }
        if (ans[i]>=1e9) {ans[i] = -1;}

        --a[i]; --b[i];
        wt[a[i]][b[i]] = w[i] = w2[a[i]][b[i]]; // update weights
        
        for (int j=0;j<n;j++) { // min dist of path of length 2 between each pair of nodes
            chmin(dist2[j][b[i]],wt[j][a[i]]+w[i]);
            chmin(dist2[a[i]][j],w[i]+wt[b[i]][j]);
        }
        for (int j=0;j<n;j++) { // add those values to dp table
            dist1[1][j] = dist2[0][j];
            distn[1][j] = dist2[j][n-1];
        }

        chmin(dist1[2][b[i]],dist1[1][a[i]]+w[i]); // for k=3: case 1 = edge is third in path
        chmin(distn[2][a[i]],w[i]+distn[1][b[i]]);

        for (int j=0;j<n;j++) { // case 2: edge is second on path
            chmin(dist1[2][j],wt[0][a[i]]+w[i]+wt[b[i]][j]);
            chmin(distn[2][j],wt[j][a[i]]+w[i]+wt[b[i]][n-1]);
        }

        chmin(dist1[3][b[i]],dist1[2][a[i]]+w[i]); // for k=4: case 1 = edge is last in path
        chmin(distn[3][a[i]],w[i]+distn[2][b[i]]);

        for (int j=0;j<n;j++) {
            chmin(dist1[3][j],dist1[1][a[i]]+w[i]+wt[b[i]][j]); // case 2: edge is second to last
            chmin(distn[3][j],wt[j][a[i]]+w[i]+distn[1][b[i]]);

            chmin(dist1[3][j],wt[0][a[i]]+w[i]+dist2[b[i]][j]); // case 3: edge is second
            chmin(distn[3][j],dist2[j][a[i]]+w[i]+wt[b[i]][n-1]);
        }

        if (a[i]==0) { // special case
            dist1[0][b[i]] = w[i]; // update for k=1
            for (int j=0;j<n;j++) {
                chmin(dist1[2][j],w[i]+dist2[b[i]][j]); // k=3 this is first in path

                for (int j2=0;j2<n;j2++) {
                    chmin(dist1[3][j],w[i]+dist2[b[i]][j2]+wt[j2][j]); // k=4 this is first in path
                }
            }
        }
        if (b[i]==n-1) { // special case (same thing)
            distn[0][a[i]] = w[i];
            for (int j=0;j<n;j++) {
                chmin(distn[2][j],dist2[j][a[i]]+w[i]);

                for (int j2=0;j2<n;j2++) {
                    chmin(distn[3][j],wt[j][j2]+dist2[j2][a[i]]+w[i]);
                }
            }
        }
    }
    for (int i=0;i<n*n;i++) {cout << ans[i] << '\n';}
}