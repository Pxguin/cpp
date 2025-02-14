# USACO Silver 2025 Jan

## 1. Cow Checkups
For $O(N^2)$, go through each pair of cows $(i,j)$ such that $a_i=b_j$. Assuming $i<j$, there are $\min(i,N-j+1)$ operations that swap this pair of cows into each other's places, so add that to the answer. Also, for a cow $a_i=b_i$, any swap disjoint from index $i$ doesn't affect this index, but index $i$ is still good after the swap, so add one to the answer for all of those indices/ranges.

To speed up to $O(N)$, we can use two pointers to easily compute the sum of all $\min(i,N-j+1)$ (for indices $i,j$ satisfying $a_i=b_j$ and $i<j$). The case where $j>i$ is done similarly and $i=j$ can be treated as a special case to avoid double counting.

## 2. Farmer John's Favorite Operation
Reduce all values mod $M$. Let $f_i(x)$ represent the minimum change needed for $a_i$ for a given $x$. We can see that $f_i(x)$ is a periodic absolute value function, and our goal is to find the minimum sum of all $f_i(x)$ at some $x$. By doing a sweep line on the breakpoints of the functions in the range $[0,M-1]$ (as we obviously only have to consider $x$ in this range), we can easily compute the sum of all $f_i(x)$ at any breakpoint and take the minimum value (as the optimal $x$ is always at a breakpoint).

$O(NlogN)$ because of sorting. My code has a ton of casework for the abs value functions because I couldn't find a better way.