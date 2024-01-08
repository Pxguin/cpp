#include <iostream>
#include <vector>
using namespace std;

vector<int> u;
vector<int> d;
vector<int> r;
vector<int> l;
int n, x, y, x2, y2;

bool check(long long v) {
    long long left = l[n]*(v/n) + l[v%n];
    long long right = r[n]*(v/n) + r[v%n];
    long long up = u[n]*(v/n) + u[v%n];
    long long down = d[n]*(v/n) + d[v%n];

    long long new_x = x+right-left;
    long long new_y = y+up-down;

    if (abs(x2-new_x)+abs(y2-new_y) <= v) {return true;}
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> x >> y >> x2 >> y2;
    cin >> n;

    u.push_back(0); d.push_back(0); r.push_back(0); l.push_back(0);

    char s;
    for (int i=0;i<n;i++) {
        cin >> s;
        u.push_back(u[i]); d.push_back(d[i]); r.push_back(r[i]); l.push_back(l[i]);
        if (s == 'U') {u[i+1]++;}
        else if (s == 'D') {d[i+1]++;}
        else if (s == 'L') {l[i+1]++;}
        else {r[i+1]++;}
    }

    long long ans = -1;

    long long low = 1;
    long long high = 1e14;
    long long mid = (low+high)/2;

    while (low <= high) {
        if (check(mid)) {
            high = mid-1;
            ans = mid;
        } else {low = mid+1;}
        mid = (low+high)/2;
    }
    cout << ans << "\n";
}