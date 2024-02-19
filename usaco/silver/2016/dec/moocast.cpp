#include <iostream>
#include <vector>

using namespace std;

int ans;
int temp;
vector<vector<int>> cows;
vector<bool> visited;

void dfs(int node) {
    if (visited[node]) {return;}
    visited[node] = true;
    temp++;
    for (int i : cows[node]) {dfs(i);}
}

int main() {
    freopen("moocast.in","r",stdin);freopen("moocast.out","w",stdout);
    int n; cin>>n; int x,y,r,x2,y2,r2,dist;
    int a[n][3];
    for (int i=0;i<n;i++) {cin >> a[i][0] >> a[i][1] >> a[i][2]; cows.push_back({});}
    for (int i=0;i<n;i++) {
        x=a[i][0],y=a[i][1],r=a[i][2];
        for (int j=i+1;j<n;j++) {
            x2=a[j][0],y2=a[j][1],r2=a[j][2];
            dist = (x2-x)*(x2-x)+(y2-y)*(y2-y);
            if (dist <= r*r) {cows[i].push_back(j);}
            if (dist <= r2*r2) {cows[j].push_back(i);}
        }
    }
    for (int i=0;i<n;i++) {
        visited.assign(n,false);
        dfs(i);
        ans=max(ans,temp);temp=0;
    }
    cout << ans;
}