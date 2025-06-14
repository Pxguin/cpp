#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        ll z = log2(sqrt(n));
        ll l4 = 1;
        for (int i=0;i<z;i++) {l4 *= 4;} // find nearest power of 4 to N

        ll a = l4+((n-=l4)/3); // find A
        ll b = 0;
        for (int bit=0;bit<60;bit+=2) { // to find B, enumerate pairs of adjacent bits in A
            bool b1 = (1LL<<bit)&a, b2 = (1LL<<(bit+1))&a;
            if (b1 && b2) {b |= (1LL<<bit);} // (these cases are proved by induction)
            else if (b1) {b |= (1LL<<(bit+1));}
            else if (b2) {b |= (1LL<<bit)|(1LL<<(bit+1));}
        }
        ll c = a^b; // C = A^B
        
        if (n%3==0) {cout << a << '\n';}
        else if (n%3==1) {cout << b << '\n';}
        else {cout << c << '\n';}
    }
}