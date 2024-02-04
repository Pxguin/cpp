#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    string s; cin >> s;
    vector<int> ctr(26,0);
    vector<vector<int>> ps;
    ps.push_back(ctr);
    for (char a : s) {
        ctr[a-'a']++;
        ps.push_back(ctr);
    }
    int q; cin >> q; int l, r;
    for (int i=0;i<q;i++) {
        cin >> l >> r;
        int chars = 0;
        for (int j=0;j<26;j++) {
            if (ps[r][j]-ps[l-1][j] > 0) {
                chars++;
            }
        }
        if (chars > 2 || l==r || s[l-1]!=s[r-1]) {cout << "YES\n";}
        else {cout << "NO\n";}
    }
}