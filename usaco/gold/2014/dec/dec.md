# USACO Gold 2014 December

## 1. Guard Mark

Use bitmask dp. $dp[S]$ is the maximum weight that can be added to a stack consisting of subset $S$ - then just try adding every cow. At the end, we will consider all subsets with height $>= H$ and take the maximum safety factor from these subsets. Complexity: $O(N2^N)$.