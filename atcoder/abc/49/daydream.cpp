#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    string s; cin >> s;
    string p[4] = {"dream","dreamer","erase","eraser"};
    bool ans = true;
    for (int i=s.size()-1;i>=0;i--) {
        bool ok = false;
        
        for (string j : p) {
            if (j.size()>i+1) {continue;}
            if (s.substr(i+1-j.size(),j.size())==j) { // is the string a suffix
                ok = true; // if so, then remove it
                i = i+1-j.size();
                break;
            }
        }
        if (!ok) {ans = false;} // if we can't remove any string then it's impossible
    } cout << (ans ? "YES" : "NO") << '\n';
}