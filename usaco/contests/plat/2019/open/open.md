# USACO Plat 2019 US Open

## 1. Tree Boxes
Consider placing the nodes in such a way that we can contain any path connecting an ancestor to a descendant with a rectangle. Then, the two rectangles simply connect $a$ to $lca(a,b)$ and $b$ to $lca(a,b)$.

It turns out that such a construction is always possible. As another note, we can try to fix the two endpoints of the path as the two corners of the bounding rectangle. We can go further, by fixing the deeper endpoint as the bottom left corner and the higher node as the top right corner. With all these constraints, a construction is pretty easy to see:
 - The subtree of $i$ must be contained inside a square of size $sz_i^2$ ($sz_i$ is the subtree size). Now consider the squares for the children of $i$. If there's only one child, then we can place $i$ in any arbitrary position to the top right of the square and still maintain a valid construction.
 - Generalizing to multiple children, we will place $i$ at the top right of the square and arrange the squares of the children in a perfectly diagonal line from the top left to the bottom right.
 - The motivation is that if a node is to the left of another node, then it must be strictly higher and strictly to the left of that node in order to satisfy all the above constraints. So we arrange the squares in the diagonal fashion.

This lets us compute the relative positions of the squares to their parents, and a second dfs lets us fix the absolute positions. After LCA precomputation, we can answer queries in $O(logN)$ for a total complexity of $O((N+Q)logN)$.

## 3. Valleys
If cells are added in order of increasing height, and edgewise-contiguous components maintained with DSU: then all components are regions satisfying the height constraint for a valley, and thus are valleys if and only if they have no holes. Conversely, every valley must be a component in the DSU at some point. So simply maintain the amount of holes in (and the size of) each component, and whenever the amount of holes reaches zero then add the size of the component to the answer.

Let time $i$ refer to the state of the above DSU after $i$ cells have been added.

If cells are added in the reverse order (decreasing height), and pointwise-contiguous components maintained with DSU: after $j$ cells have been added to this DSU, then all components that do not touch a border are holes at time $N^2-j+1$.

So we can find the number of holes at any time, and thus the change in number of holes at any time. All holes changed at time $i$ belong to the component that the cell added at time $i$ belongs to, which provides an efficient way to maintain the number of holes in each component and thus calculate the answer.

Time complexity: $O(N^2logN^2)$ from sorting.