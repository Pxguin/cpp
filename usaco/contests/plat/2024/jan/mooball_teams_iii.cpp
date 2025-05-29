#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second

const int MAX_N = 4e5, mod = 1e9+7;
const int inv_four = 250000002, inv_two = 500000004;
ll pows[MAX_N+1];
pii cows[MAX_N];
ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {ll c = (a+b)%mod; if (c<0) {c+=mod;} return c;}
int n;

struct LazySegtree {
    ll segtree[4*MAX_N], mult[4*MAX_N];

    void push(int cur) {
        segtree[cur] = mul(mult[cur],segtree[cur]);
        mult[2*cur+1] = mul(mult[2*cur+1],mult[cur]);
        mult[2*cur+2] = mul(mult[2*cur+2],mult[cur]);
        mult[cur] = 1;
    }

    void upd(int ql, int qr, int a, int cur=0, int l=0, int r=n-1) {
        if (ql>qr) {return;}
        if (l==ql && r==qr) {mult[cur] = mul(mult[cur],a);}
        else {
            push(cur);
            int m = (l+r)/2;
            upd(ql,min(qr,m),a,cur*2+1,l,m);
            upd(max(m+1,ql),qr,a,cur*2+2,m+1,r);
            segtree[cur] = add(mul(mult[cur*2+1],segtree[cur*2+1]),mul(mult[cur*2+2],segtree[cur*2+2]));
        }
    }

    void inc(int t, int a, int cur=0, int l=0, int r=n-1) {
        push(cur);
        if (l==r) {segtree[cur] = a;}
        else {
            int m = (l+r)/2;
            if (t<=m) {inc(t,a,cur*2+1,l,m);}
            else {inc(t,a,cur*2+2,m+1,r);}
            segtree[cur] = add(mul(mult[cur*2+1],segtree[cur*2+1]),mul(mult[cur*2+2],segtree[cur*2+2]));
        }
    }

    ll sum(int ql, int qr, int cur=0, int l=0, int r=n-1) {
        if (ql>qr) {return 0;}
        if (l==ql && r==qr) {return mul(segtree[cur],mult[cur]);}
        
        push(cur);
        int m = (l+r)/2;
        return add(sum(ql,min(m,qr),cur*2+1,l,m),sum(max(m+1,ql),qr,cur*2+2,m+1,r));
    }

    void reset() {
        memset(segtree,0,sizeof(segtree));
        memset(mult,1,sizeof(mult));
    }
};

struct BIT {
    int bit[MAX_N+1];
    void add(int i) {
        for (;i<=MAX_N;i+=(i&-i)) {bit[i]++;}
    }
    int sum(int i) {
        int res = 0;
        for (;i;i-=(i&-i)) {res += bit[i];}
        return res;
    }
    void reset() {
        memset(bit,0,sizeof(bit));
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    pows[0] = 1;
    for (int i=1;i<=MAX_N;i++) {pows[i] = mul(pows[i-1],2);}

    cin >> n;
    for (int i=0;i<n;i++) {cin >> cows[i].f >> cows[i].s; --cows[i].f; --cows[i].s;}

    ll ans = 0;
    for (int i=0;i<n;i++) {ans = add(ans,pows[n-1]-pows[i]);}
    ans = mul(ans,2);

    sort(cows,cows+n);
    LazySegtree st, st2; BIT fen;
    auto solve = [&]() {
        st.reset(); fen.reset(); st2.reset();
        for (int i=0;i<n;i++) {
            auto[x,y] = cows[i];

            int amt = i-fen.sum(y);
            
            st.upd(0,y-1,inv_two);
            st.inc(y,pows[i-amt + (n-1-y-amt)]);
            st2.inc(y,pows[i-amt]);

            ans = add(ans,-st.sum(y,n-2));
            ans = add(ans,st2.sum(y,n-2));

            fen.add(y+1);
            st.upd(y+1,n-1,2);
            st2.upd(y+1,n-1,2);
        }
    };

    solve();
    for (int i=0;i<n;i++) {cows[i].s = n-1-cows[i].s;}
    solve();

    ans = mul(ans,2);
    cout << ans << '\n';
}