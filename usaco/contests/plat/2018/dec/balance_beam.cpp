#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define vec vector

const int MAX_N = 1e5;
ll p[MAX_N+2], ans[MAX_N+2];

pii operator-(pii x, pii y) {return {x.f-y.f,x.s-y.s};}
ll cross(pii x, pii y) {return x.f*y.s-x.s*y.f;}
ll cross(pii x, pii y, pii z) {return cross(x-z,y-z);}

int main() {
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> p[i+1]; p[i+1]*=1e5;}
    p[0] = p[n+1] = 0;

    vec<int> st = {0};
    for (int i=1;i<=n+1;i++) { // imagine convex hull
        while (st.size()>1 && cross({i,p[i]},{st.back(),p[st.back()]},{end(st)[-2],p[end(st)[-2]]})<=0) {
            st.pop_back();
        } st.pb(i);
    }
    for (int i=0;i<st.size()-1;i++) {
        ll y = p[st[i+1]]-p[st[i]], x = st[i+1]-st[i];
        for (int j=st[i];j<st[i+1];j++) { // do math to push everything up to the convex hull
            ans[j] = ((y*(j-st[i])+(p[st[i]]*x))/x);
        }
    }
    for (int i=0;i<n;i++) {cout << ans[i+1] << '\n';}
}