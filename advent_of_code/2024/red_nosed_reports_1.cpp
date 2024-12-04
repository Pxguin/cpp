#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int ans = 0;
    
    F0R(i,n+1) {
        string s;
        getline(cin,s);
        if (!i) {continue;}
        stringstream s1(s);
        v<int> a(1);
        
        while (s1>>a.back()) {a.pb(0);}
        int m = a.size();

        bool flag1 = true, flag2 = true;
        F0R(j,m-2) {
            int dist = abs(a[j+1]-a[j]);
            if (!(a[j+1]>a[j] && dist>=1 && dist<=3)) {flag1 = false;} // increasing check
            if (!(a[j+1]<a[j] && dist>=1 && dist<=3)) {flag2 = false;} // decreasing check
        } ans += (flag1||flag2);
    } cout << ans << '\n';
}