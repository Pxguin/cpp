#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll mod = 998244353;
int add(ll a, ll b) {return (a+b+mod)%mod;}
ll mul(ll a, ll b) {return a*b%mod;}
ll p2[200001] = {1};

struct BIT {
    v<int> bit;
    BIT (int n) : bit(v<int>(n+1,0)) {};
    
    void upd(int i, int a) {
        for (;i<bit.size();i+=i&-i) {bit[i] = add(bit[i],a);}
    }
    ll sum(int i) {
        ll res = 0;
        for (;i;i-=i&-i) {res = add(res,bit[i]);}
        return res;
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();

    ll ans = 0;
    BIT ps0(n), ps1(n), ss0(n), ss1(n);
    F0R(i,n) { // initial calculation of answer
        ll sum_0 = ps0.sum(i), sum_1 = ps1.sum(i);
        if (s[i]=='0') {
            ans = add(ans,mul(sum_1,p2[n-i-1]));
            ps0.upd(i+1,p2[i]);
            ss0.upd(n-i,p2[n-i-1]);
        } else {
            ans = add(ans,mul(sum_0,p2[n-i-1]));
            ps1.upd(i+1,p2[i]);
            ss1.upd(n-i,p2[n-i-1]);
        }
    }
    int q; cin >> q;
    while (q--) {
        int i; cin >> i; 
        i--;

        if (s[i]=='0') { // casework (could probably clean up)
            ans = add(ans,mul(add(ps0.sum(i),-ps1.sum(i)),p2[n-i-1])); // update the value itself
            ps0.upd(i+1,-p2[i]); ps1.upd(i+1,p2[i]); // update prefix array
            ss0.upd(n-i,-p2[n-i-1]); ss1.upd(n-i,p2[n-i-1]); // update suffix array
            ans = add(ans,mul(add(ss0.sum(n-i-1),-ss1.sum(n-i-1)),p2[i])); // update all values that come after it
        } else {
            ans = add(ans,mul(add(ps1.sum(i),-ps0.sum(i)),p2[n-i-1]));
            ps1.upd(i+1,-p2[i]); ps0.upd(i+1,p2[i]);
            ss1.upd(n-i,-p2[n-i-1]); ss0.upd(n-i,p2[n-i-1]);

            ans = add(ans,mul(add(ss1.sum(n-i-1),-ss0.sum(n-i-1)),p2[i]));
        }

        s[i] = (s[i]=='0' ? '1' : '0');
        cout << add(ans,p2[n]-1) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    F0R(i,200000) {p2[i+1] = p2[i]*2%mod;}

    int t; cin >> t;
    while (t--) {solve();}
}