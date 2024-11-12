# USACO Gold 2017 US Open

## 1. Why Did the Cow Cross the Road
If we ignore the constraint on having to stop at every third field, then the problem is easily solved with Dijkstra. Even with that constraint, we can just create three separate instances of each field which correspond to the first field of three, the second of three, and the third (so Bessie has to eat grass here). Following the Dijkstra time complexity, it runs in $O(N^2logN^2)$.

## 2. Why Did the Cow Cross the Road II
Define $dp[i][j]$ as the maximum number of roads that can be built if we have considered up to (but not including) the $ith$ field on the top and the $jth$ field on the bottom. For $dp[i][j]$, we can either build a road between the $ith$ and $jth$ fields if possible (so push to $dp[i+1][j+1]$), or not do anything (push to $dp[i][j+1]$ and $dp[i+1][j]$). There are $N^2$ dp states so the runtime is $O(N^2)$.