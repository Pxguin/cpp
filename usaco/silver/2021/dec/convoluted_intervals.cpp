#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int a, b;
    vector<long> start(m+1,0), end(m+1,0), range_start(2*m+2,0), range_end(2*m+2,0);
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        start[a]++; end[b]++;
    }

    for (int i=0;i<m+1;i++) {
        for (int j=0;j<m+1;j++) {
            range_start[i+j] += start[i]*start[j];
            range_end[i+j] += end[i]*end[j];
        }
    }

    long ctr = 0;
    for (int i=0;i<2*m+1;i++) {
        ctr += range_start[i];
        cout << ctr << "\n";
        ctr -= range_end[i];
    }
}