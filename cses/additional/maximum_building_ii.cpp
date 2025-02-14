#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 1000;
bool a[MAX_N][MAX_N];
int l[MAX_N][MAX_N], r[MAX_N][MAX_N];
int d[MAX_N] = {0};
ll ps[MAX_N+2][MAX_N+2] = {0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char c; cin >> c;
            a[i][j] = (c=='.');
            
            if (a[i][j]) {d[j]++;}
            else {d[j] = 0;}
        }
        stack<int> s, s2;
        for (int j=0;j<m;j++) { // what bounding box will we calculate subrectangles in for each index
            while (s.size() && d[s.top()]>d[j]) {s.pop();}
            l[i][j] = (s.size() ? s.top() : -1);
            
            while (s2.size() && d[s2.top()]>=d[m-j-1]) {s2.pop();}
            r[i][m-j-1] = (s2.size() ? s2.top() : m);

            s.push(j); s2.push(m-j-1);
        }

        for (int j=0;j<m;j++) { // amt of rectangles of a fixed width increases, plateaus, then decreases
            if (!d[j]) {continue;}

            // so there's four event points to maintain for a fixed height, use difference arrays to update these points across all possible heights
            ps[0][0]++; ps[d[j]][0]--;

            int bp1 = min(j-l[i][j],r[i][j]-j);
            ps[0][bp1]--; ps[d[j]][bp1]++;

            int bp2 = max(j-l[i][j],r[i][j]-j);
            ps[0][bp2]--; ps[d[j]][bp2]++;

            ps[0][r[i][j]-l[i][j]]++; ps[d[j]][r[i][j]-l[i][j]]--;
        }
    }

    for (int i=0;i<n;i++) { // update points across all heights
        for (int j=0;j<m;j++) {ps[i+1][j] += ps[i][j];}
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {ps[i][j+1] += ps[i][j];} // calc difference array across a width

        for (int j=0;j<m;j++) { // use prefix sums to evaluate the difference arrays
            ps[i][j+1] += ps[i][j];
            cout << ps[i][j] << ' ';
        } cout << '\n';
    }
}