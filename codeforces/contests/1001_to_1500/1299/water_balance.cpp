#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define vec vector

const int MAX_N = 1e6;
ll a[MAX_N+1];
pii ps[MAX_N+1];
double ans[MAX_N+1]; 

pii operator-(pii x, pii y) {return {x.f-y.f,x.s-y.s};}
ll cross(pii x, pii y) {return x.f*y.s-x.s*y.f;}
ll cross(pii x, pii y, pii z) {return cross(x-z,y-z);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i+1]; ans[i+1] = a[i+1];}

    ps[0] = {0,0};
    for (int i=1;i<=n;i++) {
        ps[i].s = a[i]+ps[i-1].s;
        ps[i].f = i;
    } sort(ps+1,ps+n+1,[&](auto& x, auto& y) {return cross(x,y)>0;});

    vec<int> st; st.pb(0);
    for (int i=1;i<=n;i++) { // lower hull
        if (ps[i].f>ps[st.back()].f) {
            while (st.size()>1 && cross(ps[end(st)[-1]],ps[i],ps[end(st)[-2]])<0) {st.pop_back();}
            st.pb(i);
        }
    }

    for (int i=0;i<st.size()-1;i++) { // update answer with points in hull
        double sum = 0;
        for (int j=ps[st[i]].f+1;j<=ps[st[i+1]].f;j++) {sum += a[j];}
        sum /= ps[st[i+1]].f-ps[st[i]].f;
        for (int j=ps[st[i]].f+1;j<=ps[st[i+1]].f;j++) {ans[j] = sum;}
    }
    cout << fixed << setprecision(9);
    for (int i=1;i<=n;i++) {cout << ans[i] << '\n';}
}