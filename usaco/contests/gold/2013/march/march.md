# USACO Gold 2013 March

## 1. The Cow Run

Similar to Cow Checklist (Gold 2016 Dec). In fact this problem is just an easier version of that problem (define $dp[i][j][k]$ as the min cost to visit all cows from cow $i$ on the left side to cow $j$ on the right, given you are currently on the left/right side $k = 0/1$). It takes $O(N^2)$.

## 2. Hill Walk
Sweep over the endpoints of the line segments (maintain a set of currently active ranges). Whenever we drop off the current segment that Bessie is standing on, she falls to the first segment below it that is in the active set.

The set is sorted by a custom comparator that deems $a<b$ if the segment $a$ is under the segment $b$, and $a>b$ otherwise. This can be checked with cross product.

$O(NlogN)$ complexity because of a set.