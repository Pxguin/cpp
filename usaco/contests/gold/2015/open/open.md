# USACO 2015 US Open

## 2. Palindromic Paths
A palindrome can be viewed as follows: the first half of the palindrome is a path from the start position, and the second half is a path from the end position. If these two paths are identical, and end at the same cell, then a palindrome is formed. So, $dp[i][j][k]$ equals the amount of pairs of identical paths of length $i$, such that the path from the top left corner ends in row $j$ and the bottom left ends in row $k$. Note that given the row and the length of the path, we can calculate the exact cell that the path ends in. 

For each $i$, we only have to consider $j\le{i}$ and $k\ge{N-i+1}$, i.e., $i$ values of $j$ and $k$ each. Therefore, there are $1^2+2^2+\dots{+(N-1)^2}$ pairs to consider, which can be rounded to $N^3$. The memory can be reduced from $N^3$ to $N^2$ simply by reusing the dp array for each $i$. The final runtime is $O(N^3)$.