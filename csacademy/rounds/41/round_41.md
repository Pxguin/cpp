# CSA Round 41

## BFS-DFS
I'm so surprised I couldn't figure it out. The solution is so easy.

We can assert that the second element of each array must be the same. If not, it's impossible. If so, then the following construction obviously works:
 - For each node in the BFS array, draw an edge from $1$ to that node.
 - For each pair of adjacent nodes in the DFS array, draw an edge between those two nodes.

It's not hard to see why this works. Time complexity is $O(N)$.