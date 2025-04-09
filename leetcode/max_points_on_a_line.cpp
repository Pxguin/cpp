class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
            int n = points.size(), ans = 1;
            for (int i=0;i<n;i++) {
                for (int j=i+1;j<n;j++) {
                    int cnt = 0;
                    for (int k=0;k<n;k++) {
                        int cross = (points[j][0]-points[i][0])*(points[k][1]-points[i][1])-(points[k][0]-points[i][0])*(points[j][1]-points[i][1]);
                        if (cross == 0) {
                            cnt++;
                        }
                    }
                    ans = max(ans,cnt);
                }
            } return ans;
        }
    };