#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const ll mod = 1e9+7;
const ll TWO_INV = 500000004;
ll mul(ll a, ll b) {return a*b%mod;}
int add(int a, int b) {return (a+b+mod)%mod;}
ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) {res = mul(res,a);}
        a = mul(a,a); b /= 2;
    } return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    map<int,int> upd;

    F0R(i,m) {
        int l, r; cin >> l >> r;
        upd[l]^=1; upd[r+1]^=1; // invert ep
    }
    v<int> comp = {0}; // starts of each component
    int prev = 0;
    for (pii x : upd) {
        if (x.s!=prev) { // if it has a different parity, then it's a new block
            comp.pb(x.f);
        } // else, continue the old block
    }
    comp.pb(n+1);

    v<ll> ps(comp.size()), bin(comp.size()+1);
    v<int> ep;
    ps[0] = bin[comp.size()] = 0;
    F0R(i,comp.size()-1) {
        if (i&1) { // if it's a block of 1s
            ps[i+1] += comp[i+1]-comp[i]; // then add it to prefix sum
            bin[i] = mul(add(exp(2,comp[i+1]-comp[i]),-1),exp(2,n-comp[i+1]+1));
            ep.pb(comp[i+1]-1);
        }
        ps[i+1] += ps[i];
    }
    for (int i=comp.size()-1;i>=0;i--) {
        bin[i] = add(bin[i+1],bin[i]);
    }

    auto get_ones = [&](int l, int r)->int { // get #1s in any range
        int left = upper_bound(all(comp),l)-comp.begin()-1; // component start points: last thing <= l
        int right = upper_bound(all(comp),r)-comp.begin()-1; // last thing <= r

        int ret = 0;
        if (left==right) { // both in same component
            if (left&1) {ret = r-l+1;} // only if it's a 1 component
        } else {
            ret = ps[right]-ps[left+1]; // ones in between
            if (left&1) {ret += comp[left+1]-l;} // ones in left comp
            if (right&1) {ret += r-comp[right]+1;} // ones in right comp
        }
        return ret;
    };
    auto get_bin = [&](int l, int r)->ll { // get binary of any subsequence
        int left = upper_bound(all(comp),l)-comp.begin()-1; // component start points: last thing <= l
        int right = upper_bound(all(comp),r)-comp.begin()-1; // last thing <= r

        ll ret = add(bin[left+1],-bin[right]); // add middle portion
        ret = mul(ret,exp(TWO_INV,n-r)); // normal the powers of two 
        if (left&1) {ret = add(ret,mul(add(exp(2,comp[left+1]-l),-1),exp(2,r-comp[left+1]+1)));} // add left side
        if (right&1) {ret = add(ret,add(exp(2,r-comp[right]+1),-1));} // add right side
        return ret;
    };

    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        if (get_ones(l,r)>=k) { // does it just automatically work
            cout << add(exp(2,k),-1) << '\n';
        } else { // lo: first >= l                      hi: last <= l
            int lo = lower_bound(all(ep),l)-ep.begin(), hi = upper_bound(all(ep),r)-ep.begin()-1, mid = (lo+hi)/2;
            int amt = 0;
            while (lo <= hi) { // binary search on largest amount of ones we can have
                int c = get_ones(l,ep[mid]);
                if (r-ep[mid]>=k-c) { // if we can fit that amount of ones then it's good
                    lo = mid+1;
                    amt = c;
                } else {hi = mid-1;}
                mid = (lo+hi)/2;
            }
            ll ans = get_bin(r-(k-amt)+1,r); // all the ones
            ans = add(ans,mul(add(exp(2,amt),-1),exp(2,k-amt))); // the rest of the subsequence
            cout << ans << '\n';
        }
    }
}