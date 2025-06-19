# USACO Plat 2023 Jan

## 3. Subtree Activation
Call a satisfied node one whose subtree was exactly the set of activated ornaments at a previous point in time.

The sequence of operations can be divided into the following batches:
 - All nodes are off initially.
 - Turn on lights only. So optimally, start by turning on (and satisfying) a leaf node. If more lights going to be turned on, the next node that will be satisfied must be the parent of the leaf. Then the next, if needed, is the parent of the previous node, etc.
 - At the end, the set of activated ornaments is exactly the subtree of some node $x$.
 - Now, turn off lights only. Optimally, the next node satisfied is a child of $x$, then the next is a child of that child, etc. The last light turned off is a leaf.
 - Thus, at the end, all lights are turned off again.

So one of these batches is equivalent to selecting two (not necessarily distinct) leaf nodes $i$ and $j$, any common ancestor of the two, $k$, and satisfying all nodes on the union of the paths from $i$ to $k$ and from $k$ to $j$. The cost of this operation is $2\cdot sz_k$ (the subtree size of $k$).

The goal is to find the minimum cost of a set of paths such that every node belongs to at least one path.

Do dp from the leaves up. $dp[i][1]$ is the minimum cost to satisfy all nodes in the subtree of $i$, and $dp[i][0]$ is the minimum cost given there is exactly one path currently terminating at $i$. Since the cost of a path is two times the subtree size of the shallowest node on that path, we can see that it's optimal to have at most one path terminating at $i$.

Transitions: check code
 - For $dp[i][0]$: take $dp[i][1]$ for all children except one (take $dp[i][0]$ for that one)
 - For $dp[i][1]$: two cases: take $dp[i][1]$ for all children except two (which you combine into a single path that wraps around $i$) so you also have to add $2sz_i$.
 - Alternatively: extend one of the paths of the children with cost $2(sz_i-sz_c)$ for a child $c$ (since $k$ only has to be an ancestor of $i$ and $j$, not the LCA).

Time complexity: $O(N)$.