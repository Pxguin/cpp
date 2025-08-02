# USACO Plat 2018 Jan

## 2. Cow at Large
I love this problem and have always wanted to do it. As a bonus it was also my 100th problem on OI Checklist!

Let $leaf_i$ be the minimum distance from $i$ to a leaf. The answer for $i$ ($ans_i$) is the amount of nodes $u$ where out of all nodes $v$ on the path from $i$ to $u$, the only node that satisfies $dist(i,v)\ge{leaf_v}$ is $u$ itself.

The above is motivated by the greedy strategy for calculating $ans_i$ (the Gold solution):
 - Root the tree at $i$.
 - Do a dfs from $i$. Suppose we're at node $u$. If $dist(i,u)\ge{leaf_u}$, then add one to the answer and don't traverse into the subtree of $u$.

These path queries can be handled with centroid decomposition. Let the current centroid be $c$; then we process all paths contained in the centroid component of $c$, passing through $c$. Root the component at $c$.

A simple path $u\rightarrow{c}\rightarrow{v}$ is split into $u\rightarrow{c}$ and $c\rightarrow{v}$.

All nodes $x$ on the path $u\rightarrow{c}$, excluding $c$, must satisfy $dist(u,x)<leaf_x$. So, $dep_u-dep_x<leaf_x$. Simplify to $dep_u<\min(dep_x+leaf_x)$. All of $\min(dep_x+leaf_x)$ is calculated with DFS.

Additionally, all nodes $x$ on the path $c\rightarrow{v}$, excluding $v$, must satisfy $dist(u,x)<leaf_x$. $v$ must satisfy $dist(u,v)\ge{leaf_v}$.

The first condition simplifies to $dep_u+dep_x<leaf_x$, and the second $dep_u+dep_v\ge{leaf_v}$. Thus, $leaf_v-dep_v\le{dep_u}<\min(leaf_x-dep_x)$. Again, all of $\min(leaf_x-dep_x)$ is calculated with DFS.

$v$ works for any node $u$ satisfying $dep_u\in[leaf_v-dep_b,\min(leaf_x-dep_x)]$. Use prefix sums to find the amount of working $v$ for all $u$ in the centroid component of $c$.

Thus, the process is completed for $c$. Repeat across all $c$ via centroid decomposition to get the answers for each node.

Complexity: $O(NlogN)$.