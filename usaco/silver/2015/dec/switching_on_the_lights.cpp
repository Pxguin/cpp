#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int x=1;int y=1;int n;int m;int ans=1;
    int new_x,new_y;
    int a,b,c,d; // temp variables
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    cin >> n >> m;
    pair<pair<int,int>,vector<int>> rooms[n+2][n+2];
    for (int i=0;i<n+2;i++) {
        for (int j=0;j<n+2;j++) {rooms[i][j]={{0,0},{}};}
    }
    rooms[1][1]={{0,1},{}}; // start room
    for (int i=0;i<m;i++) { // lights
        cin>>a>>b>>c>>d;
        rooms[a][b].second.push_back(c);
        rooms[a][b].second.push_back(d);
    }
    queue<pair<int,int>> visit;

    // flood fill
    visit.push({1,1});
    pair<int,int> dir[4]={{0,1},{0,-1},{1,0},{-1,0}};
    while (!visit.empty()) {
        pair<int,int> room=visit.front();
        x=room.first;y=room.second;
        visit.pop();
        if (rooms[x][y].first.first==1) {continue;}
        rooms[x][y].first.first=1;

        // checking lights in current room
        for (int i=0;i<rooms[x][y].second.size();i+=2) {
            new_x=rooms[x][y].second[i];new_y=rooms[x][y].second[i+1];
            if (rooms[new_x][new_y].first.second==0) {
                // if the light in the room is not on, then turn it on
                rooms[new_x][new_y].first.second=1;
                ans++;

                for (int i=0;i<4;i++) {
                    if (rooms[new_x+dir[i].first][new_y+dir[i].second].first.first==1) {
                        visit.push({new_x,new_y});
                        break;
                    }
                }
            }
        }
        // checking neighbors
        for (int i=0;i<4;i++) {
            if (rooms[x+dir[i].first][y+dir[i].second].first.second==1) { // if light in room is on
                visit.push({x+dir[i].first,y+dir[i].second});
            }
        }
    }
    cout << ans;
}