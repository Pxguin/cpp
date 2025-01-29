# USACO Silver 2020 January

## 1. Berry Picking
Logically we want Elsie's $K/2$ baskets to all have the same amount of berries $B_i$ (let this be denoted $M$).
We can iterate over all possible $M$ and take the max.
 - All of Bessie's $K/2$ baskets should have $<= B_i$. 
 - Simply, we can iterate over all N and take as many $B_i$ as possible until we fill up the $K/2$ baskets (Elsie's baskets); if this isn't possible then we stop.
 - Then we fill up Bessie's $K/2$ baskets with the maximum possible values $<= M$, which requires sorting. 
 - This should take $O(max(B_i)*(N+NlogN))$.

 - I do this in $O(max(B_i)*N)$ by calculating all $B_i$ mod $M$, and storing the values in a frequency array.
 - Then I first assign the baskets with value $M$, and then iterate in decreasing order to fill up the remaining baskets with the maximum values possible.

## 2. Loan Repayment
Ok the solution is pretty trivial; kind of embarrassing that I didn't think of it sooner. A binary search works for $X$, and then note that $Y$ will monotonically decrease. There are only at most $\sqrt{2N}$ possible distinct values for $Y$ because $1+2+\cdots+\sqrt{2N}>{N}$. So only keep track of the points when $Y$ changes, and the algorithm becomes $O(\sqrt{N}logN)$.