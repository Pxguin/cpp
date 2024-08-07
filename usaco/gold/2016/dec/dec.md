# USACO Gold 2016 December

## 1 - Moocast

Binary search on $X$ and do dfs to check if all the cows are in the same connected component (or binary search + DSU).
It takes $O(N^2log(max_X))$ time both ways.


## 2 - Cow Checklist

Define $dp[i][j][k]$ as the minimum distance required to reach (but not including) Holstein $i$ and Guernsey $j$, with last cow $0/1$ (denoting $H/G$).
$dp[1][0][0]$ is $0$, because we start at the first Holstein.
Then for each $dp[i][j][k]$ we try to visit the next Holstein and the next Guernsey from our current cow (given by value $k$).
The answer is $dp[h][g][0]$ because we must end on the last Holstein.


## 3 - Lasers and Mirrors

We can treat the $x$ and $y$ axes as vertices, so for every mirror it connects an edge between the vertices of its $x$ and $y$ coordinates.
Then we can run bfs from the $x$ and $y$ of the start mirror to get to the $x$ or $y$ of the end mirror.