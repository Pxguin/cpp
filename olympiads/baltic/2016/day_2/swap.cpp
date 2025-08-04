#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

const int N = 2e5, l2 = 36;
bool dp[N][l2][2] = {false};
int a[N], sz[N];
int n;

vec<int> st;
vec<int> p1, p2;
queue<array<int,3>> q;

void get(vec<int>& p) {
    p.clear();
    while (q.size()) { // bfs ish
        array<int,3> cur = q.front(); q.pop(); // {index, index of cur value, cur value}
        int l = 2*cur[0]+1, r = 2*cur[0]+2, i = cur[1];
        if (l<n) {
            if (dp[cur[0]][i][0]) { // simulate swap
                q.push({{l,cur[1],cur[2]}});
                cur[1] = sz[l]-1; cur[2] = a[l];
            } else {
                q.push({{l,sz[l]-1,a[l]}});
            }

            if (r<n) {
                if (dp[cur[0]][i][1]) {
                    q.push({{r,cur[1],cur[2]}});
                    cur[2] = a[r];
                } else {
                    q.push({{r,sz[r]-1,a[r]}});
                }
            }
        }
        p.pb(cur[2]);
    }
}

bool cmp() {
    for (int i=0;i<p1.size();i++) {
        if (p1[i]>p2[i]) {return false;}
        if (p1[i]<p2[i]) {return true;}
    } return true;
}

void dfs(int cur=0) {
    sz[cur] = st.size();
    if (2*cur+1<n) { // st: keeps track of all possible values this index can take
        st.pb(a[2*cur+1]);
        dfs(2*cur+1);

        if (2*cur+2<n) {
            st.pb(a[2*cur+2]);
            dfs(2*cur+2);
            st.pop_back();
        }
        st.pop_back();

        int l = a[2*cur+1], r = (2*cur+2>=n ? 3e5 : a[2*cur+2]);
        for (int i=0;i<st.size();i++) {
            int x = st[i];

            if (l<min(x,r)) { // if l is min, then optimal to swap left only
                dp[cur][i][0] = true;
            } else if (r<min(x,l)) { // if r is min, then try both swap combinations
                dp[cur][i][0] = dp[cur][i][1] = true;
                q.push({{cur,i,x}});
                get(p1); // get(): retrieves the sequence for a subtree

                dp[cur][i][0] = false;
                q.push({{cur,i,x}});
                get(p2);

                if (cmp()) {dp[cur][i][0] = true;} // take the one that is lex min
            }
        }
    }


}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i];}

    st.pb(a[0]);
    dfs();
    q.push({{0,0,a[0]}});
    get(p1); // retrieve the answer
    for (int i=0;i<n;i++) {cout << p1[i] << ' ';}
}