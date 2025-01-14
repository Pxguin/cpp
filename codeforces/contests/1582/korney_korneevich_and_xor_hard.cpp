#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

bool dp[8192][5001] = {false};
queue<int> todo[5001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n+1);
    F0R(i,n) {cin >> a[i];}

    auto upd = [&](auto& upd, int x, int i)->void { // update with first transition
        if (i==5001 || dp[x][i]==true) {return;}
        dp[x][i] = true;
        todo[i].push(x); // mark it to be processed later
        upd(upd,x,i+1);
    };
    upd(upd,0,0);

    F0R(i,n) {
        while (todo[a[i]].size()) { // go through todo list for this a_i
            upd(upd,todo[a[i]].front()^a[i],a[i]); // try second transition for each element in todo
            todo[a[i]].pop();
        }
    }
    v<int> ans;
    F0R(i,8192) {
        if (dp[i][5000]) {ans.pb(i);}
    } cout << ans.size() << '\n';
    for (int i : ans) {cout << i << ' ';}
}