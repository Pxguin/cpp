#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);

    int n; cin >> n;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    double mx = 0; v<int> ans;
    int sum = a.back(), mn = sum;
    for (int i=n-2;i>=1;i--) {
        chmin(mn,a[i]);
        sum += a[i];
        double cand = (double)(sum-mn)/(double)(n-i-1); // what is the average in this case

        if (cand==mx) {ans.pb(i);} // if it's equal then add it to the answer
        else if (cand>mx) { // if it's better than current avg then update answer
            ans = {i};
            mx = cand;
        }
    }
    reverse(all(ans));
    for (int i : ans) {cout << i << '\n';}
}