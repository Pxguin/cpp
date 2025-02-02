# CSES Graph Section

## Planets Queries I
Use binary lifting, where the following array is precalculated: $succ[i][j]$, which denotes the $2^j$ th successor of node $i$. Queries can be answered in $O(logK)$, for a total complexity of $O((N+Q)logK)$.

## Planets Queries II
I wanted to find a more elegant solution, but looking through other's solutions as well there doesn't seem to be another common way to do it.

For each component in the functional graph, treat the cycle as a single node such that it becomes a rooted tree. If two nodes are in the same component and both aren't in the cycle, then we can calculate the distance between them by lifting node $a$ to $b$'s depth, and then checking equality. 

If $a$ is in the cycle but $b$ isn't, then it's impossible. If $b$ is in the cycle, then we first lift $a$ to the cycle, and then just find the distance between the two nodes in the cycle. This is done by comparing the relative positions to each other, which is pretty tediously done by storing the length of the cycle and also the positions of the two nodes in the cycle.

Basically, it's easier said than done. Implementation is pretty long as it requires a cycle finding algorithm (like Floyd's), then a bfs to calculate depths, then a binary lifting array, and finally casework for queries. But it only runs in $O((N+Q)logN)$.

## Planets Cycles
This is a functional/successor graph. For nodes in a cycle, then the answer for that node is the length of the cycle that it's in. For nodes not in a cycle, the answer is the distance to a cycle, plus the length of that cycle. It's clear to see that after reaching a cycle, then it'll repeat a planet after going through the cycle once.

We can calculate all cycles with Floyd's algorithm, and solve for the rest of the nodes via a dfs (on the reverse adjacency list) from each node in a cycle. The transition is clearly $ans[i]=ans[t_i]+1$.

Time complexity is thus $O(N)$.

## School Dance
This is a direct application of Kuhn's Algorithm, to compute the maximal matching in a bipartite graph. Here is a good resource: (link)[https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html].

The time complexity of Kuhn's is $O(N^3)$.