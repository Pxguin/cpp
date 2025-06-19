# USACO Plat 2024 Open

## 3. Activating Robots
For $O(2^RRN^2)$, do really simple bitmask dp. $dp[i][mask]$ is the minimum time to activate the set of robots in $mask$ given that we are currently at activation point $i$. There are $O(NR)$ transitions per dp state.

This can be rehashed by applying a velocity vector of $1\over{K}$ clockwise to everything. Then the dimension $i$ in $dp[i][mask]$, instead of size $N$, is only of size $R$. It denotes the minimum time needed to activate the set of robots in $mask$ given that we are at the $i$ th robot location. Transitions take $O(RlogN)$; we fix the next robot point that we go to and then binary search on the earliest time the next activation point reaches that location.

So it takes $O(2^RR^2logN)$. But in the transitions, it's clear that the minimum time to reach the robot point minimizes the earliest time the next activation point hits that robot location. So we don't have to binary search for every transition; only need to pass in the minimum time to reach that robot location. We can then just binary search when processing each dp value itself. It's simplified to $O(2^RR(R+logN))$.

Comment: I did not get the velocity vector observation by myself, but I got everything else. I also was not critical enough on the fact that movement is continuous and messed up because of it.