# USACO Gold 2025 US Open

## 1. Moo Decomposition
A subsequence in one copy of the string must be contained entirely in that copy only, so the answer is the amount of ways to partition one string raised to the power of $L$.

To calculate for one string, iterate from back to front. Let the amount of ways be $M$, initially $1$, and the amount of remaining O's be $P$.
 - If $s_i$ is M, then we select $K$ O's out of the $P$ we have to form a subsequence, so set $M:=M\cdot{{P}\choose{K}}$ and $P:=P-K$.
 - If $s_i$ is O, then increment $P$ by $1$ because we have one more O that can be used for a future subsequence.

After precalculating binomial coefficients, the time complexity is $O(N+logL)$.

## 2. Election Queries
$freq[i]$ equals the number of cows who vote for $i$.

Suppose we want $i$ and $j$ to be leaders. Assume WLOG $freq[i]\ge{freq[j]}$. For the first subset, go through each cow $k$ (excluding $j$) and add $\min(freq[i],freq[k])$ of the cows that vote for $k$ to this subset. i.e, construct the subset of maximum size not including any cow voting for $j$, and such that $i$ can be a leader in this subset.

Then, we see if the frequency of $j$ in the second subset (which is equal to $freq[j]$) is the maximum in that subset. More generally, $freq[i]+freq[j]\ge{\max(freq)}$, and $\min(freq[i],freq[j])>0$. We want to find such a pair $(i,j)$ as to maximize $|i-j|$.

Because $\sum{freq}$ remains constant across queries, then there are at most $\sqrt{2N}$ distinct values in $freq$. So a simple two pointers algorithm can compute the best answer in $O(\sqrt{N})$ time per query. Updating all arrays before the calculation takes $O(logN)$, so the total time complexity is $O(NlogN+Q(\sqrt{N}+logN))$.

## Comments:
1 was very easy. 2 wasn't hard but I missed the $\sqrt{2N}$ observation. 3 just seems annoying because I think you add one to the $[B+1,A]$ largest values every day which seems like a lot of casework.