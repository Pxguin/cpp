class Solution {
    public: 
        int numPoints(vector<vector<int>>& darts, int r) {
            int n = darts.size(), ans = 1;
    
            for (int i=0;i<n;i++) {
                vector<pair<double,int>> sweep;
                for (int j=0;j<n;j++) {
                    double dist = sqrt((darts[i][0]-darts[j][0])*(darts[i][0]-darts[j][0])+(darts[i][1]-darts[j][1])*(darts[i][1]-darts[j][1]));
                    if (dist>2*r || i==j) {continue;}
    
                    double t = atan2(darts[j][1]-darts[i][1],darts[j][0]-darts[i][0]);
                    double c = acos(dist/(2*r));
                    
                    sweep.push_back({-(c-t),-1});
                    sweep.push_back({c+t,1});
                }
                sort(sweep.begin(),sweep.end());
                int cur = 1;
                for (int i=0;i<sweep.size()*2;i++) {
                    cur -= sweep[i%sweep.size()].second;
                    ans = max(ans,cur);
                }
            }
            return ans;
        }
    };