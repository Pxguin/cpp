# DMOPC 2019 Contest 7

## 6. Bob Equilibrium
Define $d_i=\min(dist(i,f_i)-p_i-1,\min_{1\le{j}\le{k}}dist(i,a_j))$. Customer $i$ will visit Bob's shop at intersection $x$ iff $dist(i,x)\le{d_i}$.

It's necessary to support $N$ queries of the following:
 - Add $1$ to all vertices at most $d_i$ away from $i$.

Centroid decomposition can be used. Let $ans_i$ be the answer for node $i$; initially all values are zero.

One preliminary solution is the following: for each node $i$, iterate through all centroid ancestors. Let's say the ancestor is $A$, and the child of $A$ whose centroid subtree contains $i$ is $B$. Then we add to $ans_i$ the number of nodes $j$ in the centroid subtree of $A$ but not in the centroid subtree of $B$, that will visit Bob if $x=i$ (i.e. $dist(i,A)\le{dist(j,A)-d_j}$).

Additionally, add to $ans_i$ the number of working nodes in the centroid subtree of $i$ (which is easy).

The first part is computed by fixing $A$ and running suffix sums. Since the average depth of the centroid component of $A$ is $O(logN)$, then the time complexity is $O(NlogN+K)$.