#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int h[N];
int p[N], p2[N];

int n;
double isect(int i, int j) { // intersection of two square root functions
    double b = h[j]-h[i];
    double a = (b*b+i-j)/(-2*b);
    return a*a+j;
}

void solve() {
    deque<int> q;
    for (int i=0;i<n;i++) {
        while (q.size()>1 && isect(q[0],q[1])<=i) {q.pop_front();} // update hull (up to x-coordinate i)
        int mx = 0;
        if (q.size()) {mx = h[q.front()]+ceil(sqrt(i-q.front()));} // top line on hull = max at i 
        p[i] = max(0,mx-h[i]);

        while (q.size() && h[q.back()]+sqrt(i-q.back())<=h[i]) {q.pop_back();} // remove lines that i is always >= than
        if (q.empty() || h[q.back()]<=h[i]) { // if i will become the maximum at some point (has intersection with last line in hull)
            while (q.size()>1 && isect(i,q.back())<=isect(q.back(),q.end()[-2])) { // maintain intersection monotonicity
                q.pop_back();
            }
            q.push_back(i); // add i to hull
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i=0;i<n;i++) {cin >> h[i];}

    solve(); // solve for left
    copy(p,p+n,p2);
    reverse(h,h+n); // solve for right
    solve();
    for (int i=0;i<n;i++) {cout << max(p[n-i-1],p2[i]) << '\n';}
}