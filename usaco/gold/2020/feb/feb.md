# USACO Gold 2020 February

## 1. Timeline
If a session $b$ happens after a session $a$ then draw an edge from $a$ to $b$ - this lets us topologically sort the graph. We want this because if some session $b$ occurs after $a$, then we want to know the answer for $a$ in order to compute $b$. Following this, let $dp[i]$ represent the earliest time that session $i$ can take place. Then for a given session $i$ take all edges $j$ pointing to it. $i$ must occur at least $x_j$ days after $a_j$ for all $j$, so $dp[i] = max(a_j+x_j,S_i)$. It runs in $O(N+C)$.

## 2. Help Yourself
Instead of explicitly going over every subset of segments just find out for each segment how much it contributes to the answer. To avoid overcounting segments we'll only count for the first segment in each component. A segment will only be the first segment if no segments intersect it from the left. So, sort the points left to right and for every segment keep track of the number of active segments (including the current segment; also denote this as $K$) - all these intersect this segment, so ignore them. Then just add the sum of ${N-K}\choose{i}$ for all $0\le i\le N-K$, which equates to $2^{N-K}$. After precalculating all powers of $2$ we get a runtime of $O(N)$.

## 3. Delegation
We can iterate over all divisors $K$ of $N$, and test if the tree can be partitioned into paths of length $K$ in $O(N)$ time for each one.

To do this, for a given subtree partition of subtree $i$, we can afford having at most one path that has a length less than $K$ and goes through node $i$. This is because we can further extend that path up the tree. All other paths must be of length $K$ because they are unable to be extended; we can extend at most one path. So, let $dp[i]$ return the length of that path. There is exactly one possibility for $dp[i]$ (which can be proved by induction for all subtree depths). For some node $i$, we can combine two paths of its children $j$ and $k$ into one path of length $K$ if $dp[j]+1+dp[k]+1=K$. If no unpaired paths remain after pairing then $dp[i]=0$ because we start a new path. Otherwise, if exactly one path $dp[j]$ remains, $dp[i]=j+1$ because we continue that path via node $i$. If more than one path remains, then it's impossible to partition because we cannot simultaneously continue both paths through node $i$.

Using a map to store the $dp[j]$ for all children $j$, the time complexity is $O(N\sqrt{N}logN)$.