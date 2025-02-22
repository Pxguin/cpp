# USACO Plat 2019 US Open

## 1. Tree Boxes
Consider placing the nodes in such a way that we can contain any path connecting an ancestor to a descendant with a rectangle. Then, the two rectangles simply connect $a$ to $lca(a,b)$ and $b$ to $lca(a,b)$.

It turns out that such a construction is always possible. As another note, we can try to fix the two endpoints of the path as the two corners of the bounding rectangle. We can go further, by fixing the deeper endpoint as the bottom left corner and the higher node as the top right corner. With all these constraints, a construction is pretty easy to see:
 - The subtree of $i$ must be contained inside a square of size $sz_i^2$ ($sz_i$ is the subtree size). Now consider the squares for the children of $i$. If there's only one child, then we can place $i$ in any arbitrary position to the top right of the square and still maintain a valid construction.
 - Generalizing to multiple children, we will place $i$ at the top right of the square and arrange the squares of the children in a perfectly diagonal line from the top left to the bottom right.
 - The motivation is that if a node is to the left of another node, then it must be strictly higher and strictly to the left of that node in order to satisfy all the above constraints. So we arrange the squares in the diagonal fashion.

This lets us compute the relative positions of the squares to their parents, and a second dfs lets us fix the absolute positions. After LCA precomputation, we can answer queries in $O(logN)$ for a total complexity of $O((N+Q)logN)$.