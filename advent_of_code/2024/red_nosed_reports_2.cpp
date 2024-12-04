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
        int m = a.size()-1;

        F0R(j,m+1) { // try removing each element
            v<int> b;
            F0R(k,m) {if (k!=j) {b.pb(a[k]);}}
            bool flag1 = true, flag2 = true;
            F0R(k,b.size()-1) {
                int dist = abs(b[k+1]-b[k]);
                if (!(b[k+1]>b[k] && dist>=1 && dist<=3)) {flag1 = false;}
                if (!(b[k+1]<b[k] && dist>=1 && dist<=3)) {flag2 = false;}
            } 
            if (flag1||flag2) {ans++; break;}
        }
    } cout << ans << '\n';
}