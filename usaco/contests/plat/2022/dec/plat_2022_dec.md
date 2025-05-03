# USACO Plat 2022 Dec

## 2. Making Friends
Consider a subset of the nodes that have already left, $S$. If the subgraph induced by $S$ in the original graph is a single connected component, then in the current graph, the subgraph induced by the set of nodes $T$ will be a clique, where $i\in{T}$ if and only if $i$ has not left and $i$ is adjacent to at least one node in $S$.

So the following conclusion is reached: $i$ and $j$ will become friends if and only if the minimum maximum index on any path from $i$ to $j$ (excluding $i$ and $j$) is strictly less than $\min(i,j)$; i.e., there exists a set $S$ such that $i,j\in{T}$.

DSU and small to large merging can be used to compute the amount of pairs satisfying this in $O(Mlog^2N)$.