#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#define f first
#define s second
#define ll long long

int n, m;
vector<pair<ll,ll>> grass;

bool check(ll d) {
    int p1 = 0;
    int happy = 1;
    ll prev = grass[0].f;
    while (happy < n) {
        while (prev+d > grass[p1].s) {
            p1++;
            if (p1 == m) {return false;}
        }
        if (prev >= grass[p1].f || grass[p1].f - prev < d) {prev += d;}
        else {prev = grass[p1].f;}

        happy++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);

    cin >> n >> m;
    grass.resize(m);
    for (auto& i : grass) {
        cin >> i.f >> i.s;
    }
    sort(grass.begin(), grass.end());
    ll l = 1; ll h = grass[m-1].s - grass[0].f;
    ll d = (l+h)/2;; ll ans = -1;


    while (l <= h) {

        if (check(d)) {
            l = d+1;
            ans = d;
        } else {h = d-1;}
        d = (l+h)/2;
    }
    cout << ans << "\n";
}