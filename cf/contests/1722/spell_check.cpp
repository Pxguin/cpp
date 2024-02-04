#include <iostream>
#include <vector>
using namespace std;
 
#define ll long long
 
vector<int> alphabet(52, 0);
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n != 5) {cout << "NO\n";}
    else {
        alphabet[19] = 0;
        alphabet[34] = 0;
        alphabet[38] = 0;
        alphabet[46] = 0;
        alphabet[43] = 0;
        for (int i=0;i<5;i++) {
            alphabet[max(min(25, s[i]-'A'), s[i]-'a'+26)]++;
        }
        cout << (alphabet[19] && alphabet[34] && alphabet[38] && alphabet[46] && alphabet[43] ? "YES\n" : "NO\n");
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}