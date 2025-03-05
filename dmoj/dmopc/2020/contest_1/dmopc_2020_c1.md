# DMOPC '20 Contest 1

## 5. Victor Takes Over Canada
This is equivalent to solving [CSES - Distinct Colors](https://cses.fi/problemset/task/1139) but with queries. We need an online solution to that problem involving Euler tour that supports update queries.

First, the amount of distinct values in some node's subtree is equal to the size of the subtree minus the amount of duplicates.

Assume that there are only two nodes $a$ and $b$ of color $c$. Let $v_i$ be the number of duplicate colors in the subtree of $i$. Considering the pair $(a,b)$, we will add one to $v_i$ for every node $i$ on the path from $lca(a,b)$ to the root. This function is denoted $f(a,b)$.

This operation can be done by adding one to $v'_{lca(a,b)}$ for some array $v'$, and then $v_i$ is the sum of all $v'_j$ for all $j$ in the subtree of $i$, which is a point update range query that can be maintained with a Fenwick tree + Euler tour.

This only takes care of the case when there are exactly two nodes of color $c$ though. When there's more, then the paths become more tricky to deal with. But we can see that due to the way the Euler tour is created, we can sort all the nodes of color $c$ by their time in value, and then just apply $f$ on all pairs of adjacent nodes.

This method inherently supports update queries, so the time complexity is $O((N+Q)logN)$.