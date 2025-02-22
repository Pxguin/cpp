# USACO Plat 2020 Feb

## 1. Delegation
Binary search on $K$. Similarly to the Gold version, we have at most one path outgoing from each subtree root. Thus, we want to maximize the length of this path. Let $dp[i]$ return this value.

To compute $dp[i]$, we have to pair up at least all but one of the children's paths, so that only one path remains to pass through this node. 

There's really not a better solution that I could think of, so we can just binary search again on the maximum length of the unpaired path, and the check function returns if we can pair up the rest of the children such that each pair has a path length $\ge{K}$. That is done with a pretty simple two pointer algorithm.

Thus, it runs in $O(Nlog^2N)$.