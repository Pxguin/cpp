#include <bits/stdc++.h>

#define pii pair<int,int>
#define f first
#define s second

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<pii,vector<pii>,greater<pii>> todo; // which projects can't we start
        priority_queue<int> available; // out of projects we can start
        for (int i=0;i<n;i++) {todo.push({capital[i],i});}

        for (int i=0;i<k;i++) {
            while (todo.size() && todo.top().f<=w) { // add new projects that we can start
                available.push(profits[todo.top().s]);
                todo.pop();
            }
            if (available.size()) { // pick the project with the highest yield
                w += available.top();
                available.pop();
            }
        }
        return w;
    }
};