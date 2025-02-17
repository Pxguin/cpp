# CSES Tree

## Tree Distances I
Root the tree arbitrarily. Then, for every node $x$, define two values $f(x)$ and $g(x)$.
 - $f(x)$ is the maximum distance from node $x$ to a node inside the subtree of $x$. 
 - $g(x)$ is the maximum distance from node $x$ to a node outside the subtree of $x$.

The answer for $x$ is the maximum of $f(x)$ and $g(x)$. Calculating $f(x)$ is achieved by doing dp from the bottom-up. For a node $x$ with children $c$, $g(c)=\max(g(x)+1,f(d)+2)$ where $d$ is a child of $x$ not equal to $c$ (store the maximum and second maximum $f$ value for children of $x$). $O(N)$ ok.

## Company Queries I
Precompute for every node the ancestors $2^i$ levels above it for all possible $i$. Then use the binary representation of each $k$ (in each query) to find the $kth$ ancestor of a node. Initialize a variable $cur$ as the current node. If the $ith$ bit is turned on, then update cur as the node $2^i$ levels from $cur$. Time complexity: $O((N+Q)logN)$.

## Company Queries II
Each query translates to the least common ancestor of the given nodes. Calculate this LCA by binary lifting the nodes to the same depth. If they're equal, then that means one of them was an ancestor of the other so we return the node. Otherwise, we then lift them upwards, closer to each other, while they don't meet. The LCA will then be the parent of either node. Time complexity: $O((N+Q)logN)$.

## Distance Queries
The distance between two nodes is $depth[a]+depth[b]-2\cdot{lca(a,b)}$. Use binary lifting to calculate LCA. Time complexity: $O((N+Q)logN)$.

## Subtree Queries
Perform an Euler tour to flatten the tree into an array (push nodes based on the preorder traversal), such that each node is directly followed by all nodes in its subtree. The array can be updated and queried with a segment tree, so $O((N+Q)logN)$.