## A. Frog 1
Very simple dp; we could naively run all possible combinations but we notice that we reach some stones over and over again across all possibilities.
It is only helpful to know the minimum cost for each stone; minimum leads to minimum so we store just that.
dp[i+1] = min(dp[i+1],dp[i]+(h[i+1]-h[i])).
dp[i+2] = min(dp[i+2],dp[i]+(h[i+2]-h[i])).

## B. Frog 2
Same logic as above, but repeat for all K stones, leading to an O(NK) solution.

## C. Vacation
Define dp[i][j] as the maximum for the first i days, given that the last activity done was j.
Then for dp[i][0], try adding b[i] and c[i], for dp[i][1], try a[i] and c[i], and for dp[i][2] try a[i] and b[i].

## P. Independent Set
If a node is colored black then its parent cannot be colored black as well. In all cases though it can be colored white.
Define dp[i] as a pair storing {ways to color this subtree such that node i is white; same thing but node i is black}.
Then do a dfs bottom-up where 
 - dp[i][white] *= (dp[child][white]+dp[child][black]) for all children.
 - dp[i][black] *= dp[child][white] for all children.

## U. Grouping
Calculate the cost of each group. This can be done naively in $O(N^22^N)$ or with dp in $O(N2^N)$ (which I think is more cool, although it's trivial in terms of the whole problem).

Now let $dp_S$ be the optimal cost for the set of rabbits $S$. We can iterate over all submasks $M$ of $S$ and set $dp_S=max(dp_S,cost_M+dp_{M\oplus{S}})$ (i.e., creating the new group $M$).

### Iterating over all submasks
There's an elegant trick:

for (int submask=mask;submask>0;submask=(submask-1)&mask) {}

The operation (submask-1) deletes the last bit and sets everything after it to true, and taking the and with mask preserves only the bits in mask, so that its a valid submask. We can see that this indeed will go through all submasks of mask.

### Time complexity:
Disregarding the $O(N2^N)$, the time complexity of the dp is $\sum_{i=0}^{N}{N\choose{i}}2^i$. $i$ is the amount of set bits in the bitmask, and there are $N\choose{i}$ ways; for each way, there are $2^i$ submasks. By the binomial theorem, this expression evaluates to $(1+2)^N=3^N$, and thus the time complexity is $O(3^N)$.