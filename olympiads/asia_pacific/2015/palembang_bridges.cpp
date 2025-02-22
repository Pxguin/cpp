#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> k >> n;
    ll add = 0;
    v<pii> people;

    F0R(i,n) {
        char a, b; int c, d; 
        cin >> a >> c >> b >> d;

        if (a==b) {add += abs(d-c);}
        else {
            people.pb({c,d});
        }
    }
    sort(all(people),[&](pii a, pii b) {return a.f+a.s<b.f+b.s;});

    v<ll> cost(people.size()+1,0), cost2(people.size()+1,0);

    F0R(cnt,2) {
        priority_queue<ll,v<ll>> left;
        priority_queue<ll,v<ll>,greater<ll>> right;
        ll lsum = 0, rsum = 0;
        int c = 0;

        auto doit = [&](int a) { // find the smaller and larger halves of the set
            c++;
            if (right.size() && a>right.top()) {right.push(a); rsum += a;}
            else {left.push(a); lsum += a;}

            if (left.size()>(c+1)/2) {
                int d = left.top();
                lsum -= d; rsum += d;
                right.push(d);
                left.pop();
            } else if (right.size()>c-(c+1)/2) {
                int d = right.top();
                lsum += d; rsum -= d;
                right.pop();
                left.push(d);
            }
        };

        F0R(i,people.size()) { // split past i
            doit(people[i].f); doit(people[i].s);
            ll med = left.top();
            cost[i+1] = (med*left.size()-lsum) + (rsum-med*right.size());
        }
        swap(cost,cost2);
        reverse(all(people));
    }
    ll ans = cost.back(); // answer for one bridge
    if (k==2) {
        F0R(i,people.size()) { // combine left & right half
            chmin(ans,cost[i]+cost2[people.size()-i]);
        }
    }
    cout << ans+add+people.size() << '\n';
}