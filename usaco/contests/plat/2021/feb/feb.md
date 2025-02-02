## USACO Platinum 2021 Feb

## 1. No Time to Dry
It's definitely overkill looking at the editorial (maybe only in implementation though).

Let the minimum size set of ranges needed to paint the range $[1,N]$ be the set $R$. There is exactly one way to construct the set. The answer for some query must be a subset of $R$. Let one of the ranges $i$ in $R$ (that corresponds to color $c_i$) be <i>visible</i> for a segment $[l,r]$, if some occurence of $c$ contained in range $i$ appears in $[l,r]$.

The answer for a query $[l,r]$ is the amount of segments in $R$ intersecting $[l,r]$, minus the amount of segments that are invisible for $[l,r]$. The first part is computed with a BIT (or notice that it's the amount of segments containing $l$, plus the amount of segments starting in $[l+1,r]$). 

The second part is computed by calculating the set of ranges $S$, constructed by the following method: for each range $i$, let the occurences of $c_i$ in this range be at indices $h_1,h_2,\dots,h_k$. Then, add the ranges $[h_1+1,h_2-1],[h_2+1,h_3-1],\dots,[h_{k-1}+1,h_k-1]$ to set $S$. A query $[l,r]$ contained inside any of these ranges is invisible for range $i$. Therefore, the answer for the second part is the amount of ranges in $S$ containing $[l,r]$, which is calculated with a BIT.

Time complexity is $O((N+Q)logN+QlogQ)$.