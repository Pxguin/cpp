#include <iostream>
using namespace std;
 
#define ll long long
 
string solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i=0;i<n;i++) {
        int val = abs((s[i]-'A')-(t[i]-'A'));
        if (val != 0 && val != 5) {return "NO\n";}
    }
    return "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {cout << solve();}
}