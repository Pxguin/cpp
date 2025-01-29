#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("pairup.in","r",stdin);freopen("pairup.out","w",stdout);
    int n;cin>>n;
    int x,y;
    vector<pair<int,int>> pairs;
    for (int i=0;i<n;i++) {
        cin>>x>>y;
        pairs.push_back({y,x});
    }
    int p1=0;int p2=n-1; int subtract; int ans=0;
    sort(pairs.begin(),pairs.end());

    while (p1 <= p2) {
        subtract = min(pairs[p1].second,pairs[p2].second);
        ans = max(pairs[p1].first+pairs[p2].first,ans);
        pairs[p1].second -= subtract; pairs[p2].second -= subtract;
        if (pairs[p1].second <= 0) {p1++;}
        if (pairs[p2].second <= 0) {p2--;}
    }
    cout << ans;
}