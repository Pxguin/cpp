#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define vec vector

const int MAX_N = 1e5, B = 316;
int ans[MAX_N] = {0};
int sum[B][B] = {0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;

    priority_queue<pii,vec<pii>,greater<pii>> add, sub;
    while (k--) {
        int a, l, d; cin >> a >> l >> d;
        a--;
        if (d>=B) {
            for (int i=0;i<l;i++) { // brute force: O(\sqrt{N})
                ans[a+i*d]++;
            }
        } else { // push it into sweep line
            add.push({a,d});
            sub.push({a+(l-1)*d,d});
        }
    }

    for (int i=0;i<n;i++) {
        while (add.size() && add.top().f==i) { // add active ranges
            auto[a,d] = add.top(); add.pop();
            sum[d][a%d]++;
        }
        while (sub.size() && sub.top().f==i-1) { // delete active ranges
            auto[a,d] = sub.top(); sub.pop();
            sum[d][a%d]--;
        }
        for (int j=1;j<B;j++) { // calculate sum
            ans[i] += sum[j][i%j];
        }
        cout << ans[i] << ' ';
    }
}