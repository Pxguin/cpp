#include <bits/stdc++.h>
using namespace std;

#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<string> s(n);
    vec<int> p(n,0);
    queue<int> todo[26];
    for (int i=0;i<n;i++) {
        cin >> s[i];
    }
    string t; cin >> t;
    for (int i=0;i<n;i++) {
        todo[s[i][0]-'a'].push(i);
    }
    int ptr = 0;
    string ans;

    auto cont = [&](int i) {
        int cur = todo[i].front(); todo[i].pop();
        if (++p[cur]!=s[cur].size()) {
            todo[s[cur][p[cur]]-'a'].push(cur);
        }
    };

    while (ptr<t.size()) {
        bool stop = true, next = false;
        for (int i=0;i<26;i++) {
            if (todo[i].size()) {
                if (i+'a'!=t[ptr]) { // add as many letters that are not the next letter in t
                    ans += i+'a';
                    cont(i);
                    stop = false;
                } else {next = true;}
            }
        }
        if (!stop) {
            continue;
        } else if (next) { // if we run out of those letters, then we add the next letter in t
            ans += t[ptr];
            int rep = todo[t[ptr]-'a'].size();
            while (rep--) { // add one copy of that letter to the answer string
                cont(t[ptr]-'a');
            }
            ptr++;
        } else {break;} // if we completely run out of letters then stop
    }
    if (ptr==t.size()) {cout << "NO\n";} // if we made it through all letters in t then return no
    else {cout << "YES\n" << ans << '\n';} // otherwise yes
}