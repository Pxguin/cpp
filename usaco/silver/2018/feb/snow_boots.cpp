#include <iostream>
#include <vector>
using namespace std;

struct Boot {
    int s, d;
};

int N, B;
int s,d;
vector<Boot> boots;
vector<int> f;
int ans;
vector<vector<bool>> states;

void dfs(int cur, int b) {
    // if possible to get to end
    Boot boot = boots[b];

    if (states[cur][b]) {return;}

    states[cur][b] = true;

    if (boot.d + cur >= N-1) {
        ans = min(ans, b);
        return;
    }

    for (int i=cur+1;i<=boot.d+cur;i++) {
        if (boot.s >= f[i]) { // jumps
            dfs(i, b);
        }
    }

    for (int i=b+1;i<B;i++) {
        if (boots[i].s >= f[cur]) { // boots
            dfs(cur, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);

    cin >> N >> B;
    f.resize(N);
    states.resize(N);
    ans = B;
    for (int i=0;i<N;i++) {cin >> f[i];}
    for (int i=0;i<B;i++) {
        for (int j=0;j<N;j++) {states[j].push_back(false);}
        cin >> s >> d;
        Boot boot = {s,d};
        boots.push_back(boot);
    }
    dfs(0,0);
    cout << ans << "\n";
}