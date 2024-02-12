#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k; cin >> n >> k; k--;
    set<int> ancestors;
    int temp; int prev_ancestor = -1;
    vector<int> gaps;

    for (int i=0;i<n;i++) {cin >> temp; ancestors.insert(temp/12);}
    // all years are divided by 12 and floored

    int ans = (*ancestors.rbegin())+1;

    for (int ancestor : ancestors) {
        gaps.push_back(ancestor - prev_ancestor - 1); // this equates to 0 if they're in adjacent 12 year cycles
        prev_ancestor = ancestor;
    }
    sort(gaps.begin(),gaps.end(),greater<int>()); // sorting in descending order
    for (int i=0;i<k;i++) {ans -= gaps[i];}

    cout << ans*12;
}