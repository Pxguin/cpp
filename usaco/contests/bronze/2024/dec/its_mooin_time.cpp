#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, f; cin >> n >> f;
    int cnt[26][26] = {0}, ans[26][26] = {0};

    string s; cin >> s;
    for (int i=0;i<n-2;i++) {
        if (s[i]!=s[i+1] && s[i+1]==s[i+2]) {cnt[s[i]-'a'][s[i+1]-'a']++;}
    }
    for (int i=0;i<26;i++) {for (int j=0;j<26;j++) {ans[i][j] = cnt[i][j];}}
    for (int i=0;i<n;i++) {
        char c = s[i];
        for (int j=0;j<26;j++) { // try all change
            if (j+'a'==c) {continue;}
            s[i] = j+'a';
            for (int s1=max(0,i-2);s1<min(n-2,i+1);s1++) { // what moos did it change
                if (s[s1]!=s[s1+1] && s[s1+1]==s[s1+2]) { // ok a moo was found
                    s[i] = j+'a';
                    int rem = 0;
                    char wtf = s[s1], wth = s[s1+1];
                    s[i] = c;
                    for (int s2=max(0,i-2);s2<min(n-2,i+1);s2++) { // did this change remove any moos
                        if (s[s2]==wtf && s[s2+1]==s[s2+2] && s[s2+1]==wth) {rem++;}
                    }
                    chmax(ans[wtf-'a'][wth-'a'],cnt[wtf-'a'][wth-'a']+1-rem); // update counter
                }
            }
            s[i] = c;
        }
    }
    vec<string> why;
    for (int i=0;i<26;i++) {for (int j=0;j<26;j++) {
        if (ans[i][j]>=f) { // it's ok if the max occurences for this moo (across all changes) is >= f
            string z; z.pb(i+'a'); z.pb(j+'a'); z.pb(j+'a');
            why.pb(z);
        }
    }}
    cout << why.size() << '\n';
    for (string x : why) {cout << x << '\n';}
}