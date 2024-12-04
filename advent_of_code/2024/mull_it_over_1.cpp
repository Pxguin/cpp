#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll ans = 0;
    while (true) {
        string s; getline(cin,s);
        if (s.empty()) {break;}
        int n = s.size();
        s += "....";
        F0R(i,n) {
            if (s[i]=='m'&&s[i+1]=='u'&&s[i+2]=='l'&&s[i+3]=='(') { // initial check "mul("
                i += 4;
                string a, b;
                while (i<n && s[i]-'0'>=0&&s[i]-'0'<=9) {a += s[i++];} // first number
                if (!(i<n && s[i]==',')) {i--; continue;} // middle comma
                while (++i<n && s[i]-'0'>=0&&s[i]-'0'<=9) {b += s[i];} // second number
                if (!(i<n && s[i]==')')) {i--; continue;} // closing parentheses
                ans += (ll)stoi(a)*stoi(b);
            }
        } 
    } cout << ans << '\n';
}