#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    if (n%4==1 || n%4==2) {cout << "NO\n";}
    else {
        cout << "YES\n";
        vec<int> s1, s2;
        if (n%4==3) {s1 = {1,2}; s2 = {3};}
        for (int i=n%4+1;i<=n;i+=4) {
            s1.pb(i); s1.pb(i+3);
            s2.pb(i+1); s2.pb(i+2);
        }
        cout << s1.size() << '\n';
        for (int x : s1) {cout << x << ' ';}
        cout << '\n' << s2.size() << '\n';
        for (int x : s2) {cout << x << ' ';}
    }
}