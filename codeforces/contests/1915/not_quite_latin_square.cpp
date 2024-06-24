#include <iostream>
#include <unordered_map>
using namespace std;
 
void solve() {
    string s;
    unordered_map<char, bool> z;
 
    for (int i=0;i<3;i++) {
        z['A'] = 0; z['B'] = 0; z['C'] = 0; z['?'] = 0;
        cin >> s;
        for (char a : s) {
            z[a] = 1;
        }
        if (z['?']) {
            if (!z['A']) {cout << 'A';}
            else if (!z['B']) {cout << 'B';}
            else {cout << 'C';}
            cout << "\n";
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}
