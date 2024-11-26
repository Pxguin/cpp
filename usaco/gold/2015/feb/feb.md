# USACO Gold 2015 Feb

## 1. Cow Hopscotch (Gold)
I define $g[i][j]$ as the given grid. 

Run the same idea as in the silver version. However, transitions will be faster as we can instead calculate the answer with complementary counting — for $dp[i][j]$, it's the sum of $dp[a][b]$ for $a<i; b<j$ minus the sum of $dp[a][b]$ with $g[a][b]=g[i][j]$. The first part is computed with 2d prefix sums, and the second part is computed with BITs that we'll update after processing every row. For each color, we'll individually store a BIT across all columns, such that we can calculate the total $dp$ sum for any color across any prefix of columns. It would take $KC$ memory but can be reduced to $K$ if we only store the columns that each color appears in, rather than store all columns for each color. These optimizations reduce the runtime from $O(R^2C^2)$ to $O(RClogC)$.