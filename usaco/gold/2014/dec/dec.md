# USACO Gold 2014 December

## 1. Guard Mark
Use bitmask dp. $dp[S]$ is the maximum weight that can be added to a stack consisting of subset $S$ - then just try adding every cow. At the end, we will consider all subsets with height $>= H$ and take the maximum safety factor from these subsets. Complexity: $O(N2^N)$.

## 3. Cow Jog
$p_i,s_i$ = starting position and speed of cow $i$. Create the range of distance covered $[p_i,p_i+s_i*T]$ for each cow. 

We can see that cow $j$ runs into cow $i$ if $p_j<p_i$ and $p_j+s_j\cdot{T}\ge{p_i+s_i\cdot{T}}$. The minimum number of subsets to cover all cows, such that no two cows in a subset satisfy the above property, is a well-known problem. After sorting all cows by increasing $p$ value, the answer comes from the length of the longest non-increasing subsequence of the array $a$, such that $a_i=p_i+s_i\cdot{T}$. Time complexity: $O(NlogN)$.