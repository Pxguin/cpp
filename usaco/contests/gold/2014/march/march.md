# USACO Gold 2014 March

## 2. Sabotage
Assume the range for deletion has already been selected. Let the average out of all remaining machines be $A$. We can subtract $A$ from each $M_i$ in the remaining set to get the sum to equal zero.

More generally, for a candidate average $A$, the average of the remaining machines is $\le{A}$ if the sum after subtracting $A$ from each is non-positive, and $>A$ otherwise. $A$ can be binary searched on, but it now remains to find the range that we should delete. As to minimize the sum of the remaining machines, we remove the subarray with the largest sum, which is a well-known problem. So, $O(NlogM)$ computation.

Another way to get to the above is by using the average formula: let $T=\sum_{i=0}^N{M_i}$ and $[l,r]$ be the range we have selected for deletion. $S=\sum_{i=l}^r{M_i}$ and $R=r-l+1$.

Now the check function is $(T-S)/(N-R)\le{A}$, to $(T-S)\le{AN-AR}$, to $T-(S-AR)\le{AN}$, to $(T-AN)-(S-AR)\le{0}$. $(S-AR)$ is the maximum subarray that we are looking for, and so $(T-AN)-(S-AR)$ gives the sum of all remaining machines. So it's the same.