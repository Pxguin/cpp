# USACO Gold 2023 US Open

## 1. Custodial Cleanup
First, get all keys possible. This is done through a BFS process — we can visit all nodes that we currently have the keys too. When we pick up a new key, we have to do some backtracking to figure out which new nodes are visitable.

There will be nodes $i$ that we can't visit. In this case, we can't get or place keys in those stalls, so the only way to reassign all keys is if $s_i=f_i$ to begin with. For the second part, I'll assume that these defunct nodes have been removed from the graph for simplicity.

The second part is to check if we can place all keys in their correct stalls. For a key of given color $C$, after placing down the last key of color $C$, then we can't traverse through any more stalls with color $C$ to get back to node $1$. In other words, letting $X$ be the color of the stall that the last key of color $C$ was placed in, there should exist a path from stall $1$ to that stall such that no stall of color $C$ is on the path (excluding endpoints).

We can simulate the process in reverse; we start from node $1$ and can only visit stalls of color $C$ after traversing some stall satisfying $f_i=C$ (thus ensuring that it's the last stall we place a key of color $C$ in, so there's a simple path back to node $1$ not going through any stalls of color $C$).

Time complexity is $O(N+M)$.