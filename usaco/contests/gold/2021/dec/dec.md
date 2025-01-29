# USACO Gold 2021 December

## 1. Paired Up
Create a range $[x_i,x_i+K]$ for each cow (this is sufficient instead of $[x_i-K,x_i+K]$). Observe the following:
 - To satisfy the third constraint, all ranges for unpaired cows must be disjoint (even at endpoints).
 - To satisfy the first two constraints, all connected components of ranges of paired cows must have an even number of nodes.

To start, find all connected components in $O(N)$. We can now solve $T=1$, as we want to remove exactly one range from every component with an odd size, such that all remaining components have even size. Iterate through each range in each component and see if removing it is valid. This is the case if the resulting component(s) both have even size.

$T=2$ is slightly different. WLOG assume there's one component. Then let $dp[i][0/1]$ be the maximum weight of unpaired cows up to $i$, given the parity of all unpaired cows so far is $0/1$. We can either pair up this cow and so transition to $dp[i][1/0]$, or leave it unpaired. In this case, binary search on the earliest cow $j$ that can also be left unpaired if $i$ is left unpaired. Then, all cows from $[i+1,j-1]$ must be paired. 

If the last cow in the component is $N'$, then add $dp[N'][0]$ to the answer. This runs in $O(NlogN)$; I'm pretty sure that a similar dp can be done as well for $T=1$.

## 2. HILO
Consider some HILO pair consisting of indices $i$ and $j$ ($i<j$). If you sort the array up to $j$, then $i$ and $j$ should be adjacent. Therefore, if each index is the LO in a HILO pair, then there is exactly one index that can contribute the HI in this pair. Store these indices in an array $hi[i]$.

So we can iterate over all $x$ in increasing order and store which indices Elsie says LO at (array $L$). When transitioning from $x$ to $x+1$, we remove a suffix of $L$ and then append $x+1$; these operations can be performed with a stack. To calculate the answer for $x$, it would suffice to iterate over each element $i$ in the array $L$. The amount of times Elsie says HILO must be equal to the amount of unique $hi[i]$; if some $i$ is not part of a HILO pair, then this is only because $hi[i]$ is already part of a HILO pair with another index (so $hi[i]$ is still counted in the end). Finding and updating the number of unique $h[i]$ can be done with a frequency array. Preprocessing of $O(NlogN)$, but the main algorithm takes $O(N)$. 