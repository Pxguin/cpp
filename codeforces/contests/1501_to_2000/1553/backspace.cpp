#include <iostream>
using namespace std;
 
void solve() {
    string s, t; cin >> s >> t;
    if ((s.size()-t.size())%2 == 1) {s.erase(0,1);}
    
    int p1 = 0;
    for (int p2=0;p2<t.size();p2++) {
        if (p1 == s.size()) {cout << "NO\n"; return;}
        //cout << t[p1] << s[p2];
        while (s[p1] != t[p2]) {
            p1 += 2;
            if (p1 >= s.size()) {
                cout << "NO\n"; return;
            }
        }
        p1++;
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}