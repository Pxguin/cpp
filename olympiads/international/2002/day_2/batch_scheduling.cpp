#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second

const int MAX_N = 1e4;
int t[MAX_N], F[MAX_N];

double isect(pii a, pii b) {return (double)(a.s-b.s)/(b.f-a.f);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, S; cin >> n >> S;
    for (int i=0;i<n;i++) {
        cin >> t[i] >> F[i];
    }
    ll t_sum = 0, f_sum = 0;
    deque<pii> q; q.push_back({0,0});
    ll ans = 0;
    
    for (int i=n-1;i>=0;i--) {
        f_sum += F[i]; t_sum += t[i]; // suffix sums
        while (q.size()>1 && isect(q[0],q[1])<=f_sum) {q.pop_front();} // cht
        ans = f_sum*t_sum+f_sum*S + q.front().f*f_sum+q.front().s;

        pii line = {-t_sum,ans+f_sum*S-f_sum*t_sum+(t_sum-S)*f_sum};
        while (q.size()>1 && isect(line,q.end()[-2])<=isect(q.end()[-2],q.back())) {q.pop_back();}
        q.push_back(line);
    } cout << ans << '\n';
}