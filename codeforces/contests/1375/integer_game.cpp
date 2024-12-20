#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cout << "First" << endl;
    ll a[3]; cin >> a[0] >> a[1] >> a[2];
    F0R(i,3) {
        ll s[3] = {a[0],a[1],a[2]}; sort(s,s+3);
        ll c = (s[1]-s[0]==s[2]-s[1] ? s[1]-s[0] : s[2]-s[1]+s[2]-s[0]);
        cout << c << endl;
        
        int ret; cin >> ret;
        if (ret==0) {break;}
        else {a[ret-1] += c;}
    }
}