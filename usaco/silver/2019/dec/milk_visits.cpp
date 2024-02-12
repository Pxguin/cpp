#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> farms;
vector<bool> visited;
int start,finish,ans;
char type;
vector<int> comps;
int comp=0;

void dfs(int node) {
    if (visited[node]) {return;}
    comps[node]=comp;
    visited[node] = true;

    for (auto i=farms[node].begin()+1;i<farms[node].end();i++) {
        if (farms[*i][0] == type) {dfs(*i);}
    }
}

int main() {
    freopen("milkvisits.in","r",stdin);freopen("milkvisits.out","w",stdout);
    int n,m; cin>>n>>m;
    for (int i=0;i<n;i++) {cin>>type;farms.push_back({type});}
    for (int i=0;i<n-1;i++) {
        int temp1,temp2; cin>>temp1>>temp2;
        farms[temp1-1].push_back(temp2-1);
        farms[temp2-1].push_back(temp1-1);
    }
    comps.assign(n,0);
    visited.assign(n,false);
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            comp++;
            type=farms[i][0];
            dfs(i);
        }
    }
    
    int prev_size; char pref;
    for (int i=0;i<m;i++) {
        cin>>start>>finish>>pref;
        start--;finish--;
        ans=1;
        if ((comps[start]==comps[finish]) && (pref != farms[start][0])) {ans=0;}
        cout << ans;
    }
}