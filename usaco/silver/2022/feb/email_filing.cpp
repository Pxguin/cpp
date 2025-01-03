#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

bool solve() {
    int m, n, k; cin >> m >> n >> k;
    v<int> f(n), rem(m);
    F0R(i,n) {cin >> f[i]; f[i]--; rem[f[i]]++;}
    
    v<int> prev(n), nxt(n);
    F0R(i,n) {prev[i] = i-1; nxt[i] = i+1;}

    m++;
    queue<int> todo;
    int top = 0, bottom = k-1, curf = k-1;
    v<queue<int>> emails(m);
    F0R(i,k) {emails[f[i]].push(i); todo.push(f[i]);}

    auto scrolldown = [&](int x) { // scrolling down always exposes a new email
        bottom = nxt[bottom]; 
        emails[f[bottom]].push(bottom); todo.push(f[bottom]);
        if (top==x) {top = nxt[top];} // if we filed the email at the top, then move the top ptr down
        if (x==-1) {emails[f[top]].pop(); top = nxt[top];} // special case (when we want to scroll all emails down for now)
    };
    auto remove = [&](int x) {
        emails[f[x]].pop(); rem[f[x]]--; // dealing with removal (rem stores how many emails of each folder are not filed yet)
        if (prev[x]!=-1) {nxt[prev[x]] = nxt[x];} // update DLL
        if (nxt[x]!=n) {prev[nxt[x]] = prev[x];}
        
        if (nxt[bottom]==n) { // do we have to scroll up?
            if (bottom==x) {bottom = prev[bottom];} // update the bottom pointer
            if (prev[top]==-1) { // update top pointer
                if (x==top) {top = nxt[top];}
            } else {
                top = prev[top];
                if (top!=-1) {emails[f[top]].push(top); todo.push(f[top]);}
            }
        } else { // we scroll down
            scrolldown(x);
        }
    };
    while (true) {
        while (todo.size()) { // todo stores all the folders that we have to consider
            int folder = todo.front(); todo.pop();
            if (folder==m || emails[folder].empty() || folder>curf) {continue;}

            while (emails[folder].size()) { // file all emails that can go into this folder
                int x = emails[folder].front();
                remove(x); // remove from the list of emails
            }
            while (curf<m && rem[curf-k+1]==0) {curf++; todo.push(curf);} // scroll folders if possible
        }

        if (curf==m) {return true;} // if we have filed all emails, then we succeed
        if (nxt[bottom]==n) {return false;} // we have not succeeded, return false if we can't scroll down anymore

        scrolldown(-1); // otherwise, scroll down one to expose more emails
        todo.push(f[bottom]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {cout << (solve() ? "YES" : "NO") << '\n';}
}