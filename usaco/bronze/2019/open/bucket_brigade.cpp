#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("buckets.in","r",stdin);
    freopen("buckets.out","w",stdout);
    char f;
    pair<int,int> b;
    pair<int,int> l;
    pair<int,int> r;
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            cin >> f;
            if (f == 'B') {b = make_pair(i,j);}
            else if (f == 'L') {l = make_pair(i,j);}
            else if (f == 'R') {r = make_pair(i,j);}
        }
    }
    int ans = abs(b.first-l.first)+abs(b.second-l.second)-1;

    if ((b.first == l.first && l.first == r.first && (max(b.second,l.second)>r.second && r.second>min(b.second,l.second)))
    || (b.second == l.second && l.second == r.second && (max(b.first,l.first)>r.first && r.first>min(b.first,l.first)))) {
        ans += 2;
    } cout << ans << "\n";

}