#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 1e5, B = 1000;
struct Student {
    int a, b, id;
    bool operator<(const Student& o) const {return a<o.a;}
};
struct Query { // redundant
    int a, b, c, id;
    bool operator<(const Query& o) const {return c>o.c;}
};

Student st[MAX_N], st2[MAX_N];
int mn[MAX_N];

Query qry[MAX_N];
int ans[MAX_N] = {0};
ordered_set<int> sets[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;

    for (int i=0;i<n;i++) {cin >> st[i].a >> st[i].b;}
    sort(st,st+n);
    for (int i=0;i<n;i++) {st[i].id = i/B;}
    for (int i=0;i<(n+B-1)/B;i++) {mn[i] = st[i*B].a;}
    copy(st,st+n,st2);

    sort(st,st+n,[&](const Student& x, const Student& y) {return x.a+x.b>y.a+y.b;});
    for (int i=0;i<q;i++) {cin >> qry[i].a >> qry[i].b >> qry[i].c; qry[i].id = i;}
    sort(qry,qry+q);

    for (int i=0,p=0;i<q;i++) {
        while (p<n && st[p].a+st[p].b>=qry[i].c) { // sort by c
            sets[st[p].id].insert(st[p].b); // divide students (when sorted by a) in sqrt(n/logn) blocks 
            p++;
        }
        for (int j=(n+B-1)/B-1;j>=0;j--) { // iterate through blocks to count number of students satisfying condition
            if (mn[j]<qry[i].a) { // if not all students in this block satisfy S>=A then manually iterate through block
                for (int k=j*B;k<min(j*B+B,n);k++) {
                    ans[qry[i].id] += (st2[k].a+st2[k].b>=qry[i].c && st2[k].a>=qry[i].a && st2[k].b>=qry[i].b);
                } break; // then terminate process
            } else {ans[qry[i].id] += sets[j].size()-sets[j].order_of_key(qry[i].b);} // if all students satisfy S>=A then binary search to count # satisfying T>=B
        }
    }
    for (int i=0;i<q;i++) {cout << ans[i] << '\n';}
}