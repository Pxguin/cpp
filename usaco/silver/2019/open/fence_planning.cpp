#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    freopen("fenceplan.in","r",stdin);freopen("fenceplan.out","w",stdout);
    int n,m; cin>>n>>m; int temp,temp2;
    pair<int,int> x,y;
    pair<int,int> grid[n];
    int ans=10*10*10*10*10*10*10*10*10;
    vector<int> graph[n];
    bool visited[n];
    for (int i=0;i<n;i++) {visited[i]=false;}
    for (int i=0;i<n;i++) {cin >> grid[i].first >> grid[i].second;}
    for (int i=0;i<m;i++) {
        cin >> temp >> temp2;temp--;temp2--;
        graph[temp].push_back(temp2);graph[temp2].push_back(temp);
    }

    stack<int> visit;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            visit.push(i);
            x={grid[i].first,grid[i].first};
            y={grid[i].second,grid[i].second};
            while (!visit.empty()) {
                temp=visit.top();visit.pop();
                visited[temp]=true;
                x={min(x.first,grid[temp].first),max(x.second,grid[temp].first)};
                y={min(y.first,grid[temp].second),max(y.second,grid[temp].second)};
                for (auto j=graph[temp].begin();j<graph[temp].end();j++) {
                    if (!visited[*j]) {visit.push(*j);}
                }
            }
            ans=min(ans,((x.second-x.first)+(y.second-y.first))*2);
        }
    }
    cout << ans;
}