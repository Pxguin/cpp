# USACO Plat 2015 Dec

## 1. Max Flow
Assume that all paths connect an ancestor to a descendant. We can calculate the answer as the maximum amount of paths going through a node, which is precisely the amount of paths ending in the subtree, minus the amount of paths starting in the subtree, plus the amount of paths starting at the current node. Calculate this with dfs.

For paths $(x,y)$ not connecting an ancestor to a descendant, we can split them into such. The first path consists of a single node (the LCA). The second connects $x$ to the node just below the LCA. The third connects $b$ to the node just below the LCA.

It runs in $O((N+M)logN)$.