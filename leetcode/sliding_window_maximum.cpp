using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            multiset<int> window;
            vector<int> ret;
            for (int i=0;i<n;i++) {
                window.insert(nums[i]);
                if (window.size()==k) {
                    ret.push_back(*(window.rbegin()));
                    window.erase(window.find(nums[i-k+1]));
                }
            } return ret;
        }
    };