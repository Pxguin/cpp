#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll ans = 0;
    bool ok = true;
    while (true) {
        string s; getline(cin,s);
        if (s.empty()) {break;}
        int n = s.size();
        s += ".......";
        F0R(i,n) {
            if (s.substr(i,7)=="don't()") {ok = false;} // don't
            else if (s.substr(i,4)=="do()") {ok = true;} // do
            else if (s.substr(i,4)=="mul(" && ok) { // only do it if ok=true (last statement was a "do")
                i += 4;
                string a, b;
                while (i<n && s[i]-'0'>=0&&s[i]-'0'<=9) {a += s[i++];}
                if (!(i<n && s[i]==',')) {i--; continue;}
                while (++i<n && s[i]-'0'>=0&&s[i]-'0'<=9) {b += s[i];}
                if (!(i<n && s[i]==')')) {i--; continue;}
                ans += (ll)stoi(a)*stoi(b);
            }
        }
    } cout << ans << '\n';
}