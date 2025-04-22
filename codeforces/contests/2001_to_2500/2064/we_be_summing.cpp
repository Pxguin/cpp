#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

bool check(pair<pii,int> a, pair<pii,int> b) { // does a intersect b, and index for a < index for b
    return b.s>a.s && b.f.f<a.f.s;
}

void solve() {
    int n, k; cin >> n >> k;
    vec<int> a(n), mn_l(n), mn_r(n), mx_l(n), mx_r(n);
    for (int i=0;i<n;i++) {cin >> a[i];}

    stack<int> mns, mns2;
    for (int i=0;i<n;i++) { // nearest <= val on left, < val on right
        while (mns.size() && a[i]<a[mns.top()]) {mns.pop();}
        while (mns2.size() && a[n-i-1]<=a[mns2.top()]) {mns2.pop();}
        mn_l[i] = (mns.size() ? mns.top() : -1);
        mn_r[n-i-1] = (mns2.size() ? mns2.top() : n);
        mns.push(i); mns2.push(n-i-1);
    }
    stack<int> mxs, mxs2;
    for (int i=0;i<n;i++) { // nearest > val on left, >= val on right
        while (mxs.size() && a[i]>=a[mxs.top()]) {mxs.pop();}
        while (mxs2.size() && a[n-i-1]>a[mxs2.top()]) {mxs2.pop();}
        mx_l[i] = (mxs.size() ? mxs.top() : -1);
        mx_r[n-i-1] = (mxs2.size() ? mxs2.top() : n);
        mxs.push(i); mxs2.push(n-i-1);
    }
    vec<queue<pair<pii,int>>> mn_q(n+1), mx_q(n+1);
    for (int i=0;i<n;i++) { // group by a[i] value
        mn_q[a[i]].push({{mn_l[i],mn_r[i]},i}); // {{left,right},index}
        mx_q[a[i]].push({{mx_l[i],mx_r[i]},i});
    }

    ll ans = 0;
    for (int x=1;x<=n;x++) {
        if (k-x>n || k-x<1) {continue;}
        
        queue<pair<pii,int>> active;
        ll sum = 0;
        while (mn_q[x].size()) { // pair up x and k-x
            while (mx_q[k-x].size() && mn_q[x].front().s>=mx_q[k-x].front().s) {mx_q[k-x].pop();}
            // get rid of ones from k-x list while they have greater indices
            
            while (mx_q[k-x].size() && check(mn_q[x].front(),mx_q[k-x].front())) { // add segments which intersect
                sum += mx_q[k-x].front().f.s-mx_q[k-x].front().s; // amount of possible right endpoints
                active.push(mx_q[k-x].front());
                mx_q[k-x].pop();
            }
            while (active.size() && !check(mn_q[x].front(),active.front())) { // remove ones which don't intersect anymore
                sum -= active.front().f.s-active.front().s;
                active.pop();
            }
            ans += sum*(mn_q[x].front().s-mn_q[x].front().f.f); // right endpoints * left endpoints
            mn_q[x].pop(); // continue to next
        }
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}