#include <iostream>
#include <algorithm>
using namespace std;
 
void solve() {
    int n; cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {cin >> a[i];}
    sort(a, a+n);
    
    long long count1 = 0; 
    long long count2 = 0;
    long long count = 0;
    long long num = a[0];
    long long sum = 0;
    for (int i=0;i<n;i++){
        if (a[i] == 1) {count1++;}
        else if (a[i] == 2) {count2++;}
        if (a[i] == num) {
            count++;
            sum += count-1;
        } else {
            count = 1;
            num = a[i];
        }
    }
    sum += (count1*count2);
    cout << sum << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {solve();}
}
