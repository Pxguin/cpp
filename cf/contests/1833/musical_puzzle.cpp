#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
 
int solve() {
    unordered_set<string> melodies;
    int n; cin >> n;
    string s; cin >> s;
    for (int i=1;i<n;i++) {
        melodies.insert(s.substr(i-1,2));
    } cout << melodies.size() << "\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}