# USACO Plat 2022 Open

## 3. Up Down Subsequence
Split the string into blocks of U's and D's. For the U blocks, it is necessary to find an increasing subsequence, and decreasing otherwise.

Consider the first block of characters (and assume WLOG that it's U's). Let it's length be $L$; then we want to find the smallest $j$ such that there exists an increasing subsequence of length $L+1$ in the first $j$ cows. Finding the minimum $j$ lets us assert that in an optimal construction, the cow corresponding to the last U in this block will have an index $\ge{j}$, and a value $\ge{a_j}$.

So then we simply transition to the next block, which consists of D's, and find a decreasing subsequence in the range $[j,N]$ just as we found the increasing subsequence.

Continue through all the blocks, and we get the answer in $O(NlogN)$.