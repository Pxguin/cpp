# USACO Gold 2013 March

## 1. The Cow Run

Similar to Cow Checklist (Gold 2016 Dec). In fact this problem is just an easier version of that problem (define $dp[i][j][k]$ as the min cost to visit all cows from cow $i$ on the left side to cow $j$ on the right, given you are currently on the left/right side $k = 0/1$). It takes $O(N^2)$.