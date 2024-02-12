#include <iostream>
#include <vector>
using namespace std;

// works for any length of preferences

#define f first
#define s second
#define mp make_pair

int ans = 0;
int z = 2;

void solve(int cow, int pref, int box, vector<pair<int,int>>& boxes, vector<vector<int>>& p) {
    bool works = false;
    if (boxes[box] != mp(-1,-1)) {
        if (boxes[box].f > cow) {
            works = true;
            if (boxes[box].s+1 < z) {
                solve(boxes[box].f, boxes[box].s+1, p[boxes[box].f][boxes[box].s+1], boxes, p);
            }
        }
    } else {ans++; works = true;}
    if (works) {boxes[box] = mp(cow, pref);}

}

int main() {
    freopen("cereal.in","r",stdin); freopen("cereal.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, a;
    cin >> n >> m;
    vector<vector<int>> p(n);
    vector<pair<int,int>> boxes(m,mp(-1,-1));
    for (int i=0;i<n;i++) {
        for (int j=0;j<z;j++) {
            cin >> a; a--;
            p[i].push_back(a);
        }
    }

    int answers[n];
    for (int i=n-1;i>=0;i--) {
        solve(i, 0, p[i][0], boxes, p);
        answers[i] = ans;
    }
    for (int i : answers) {cout << i << "\n";}
}