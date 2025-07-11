# USACO Plat 2022 Dec

## 1. Breakdown
Process updates in reverse. The simplest strategy is to maintain a dp table of size $O(NK)$ ($dp[k][i]$ is the min cost of a path from $1$ to $i$ with $k$ edges, up to $k=8$) and update in $O(N^2K)$ per query. But this takes $O(N^4K)$ and times out.

We need to update this dp table differently by taking advantage of the fact that $k$ is small, so it may be more worth it to update $dp[k]$ independently of $dp[k-1]$. Since we can anticipate that updating all of $dp[k]$ will take time proportional to $k$, then we should consider splitting the table in two halves: $dp1[k][i]$ stores the min cost of a path from $1$ to $i$ with $k$ edges (up to $k=4$), and $dp2[k][i]$ stores the min cost for a path from $i$ to $N$.

The following only considers $dp1$ (but $dp2$ is updated similarly). We want to update all dp values when adding in a new edge to the graph.

The easy cases are $k=1$ and $k=2$, which can be done in $O(1)$ and $O(2N)$ time respectively (for $k=2$: the new edge is either first or second in the path).

For $k=3$, we choose to either have the new edge first, second, or third in the path. When it's second or third in the path, this practically reduces to the $k=2$ transitions. The only new case is when the new edge is first, in which case there are still two edges after it in the path. To solve this, we can create a helper array $mn[i][j]$ which stores the minimum cost of a path of length $2$ from $i$ to $j$. That is just a generalized version of the $k=2$ update and is done in $O(2N)$ as well. Then this case is solved in $O(N)$.

For $k=4$, the cases when the new edge is second, third, or fourth reduces to $k=3$ transitions. The hard case is when it's first in the path, but only $N$ of these edges exist, so we can afford to do the easy $O(N^2)$ update (by yet again utilizing the $mn$ array).

Thus, the time complexity is $O(N^3K^2)$.

## 2. Making Friends
Consider a subset of the nodes that have already left, $S$. If the subgraph induced by $S$ in the original graph is a single connected component, then in the current graph, the subgraph induced by the set of nodes $T$ will be a clique, where $i\in{T}$ if and only if $i$ has not left and $i$ is adjacent to at least one node in $S$.

So the following conclusion is reached: $i$ and $j$ will become friends if and only if the minimum maximum index on any path from $i$ to $j$ (excluding $i$ and $j$) is strictly less than $\min(i,j)$; i.e., there exists a set $S$ such that $i,j\in{T}$.

DSU and small to large merging can be used to compute the amount of pairs satisfying this in $O(Mlog^2N)$.