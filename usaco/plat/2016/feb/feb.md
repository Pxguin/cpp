# USACO Platinum 2016 February

## 2. Fenced In

(solve the Gold version before).

(or at least solve it but not implement it, like me lmao)

We still want to find an MST but need to do it faster. Now if we rename the # of horizontal fences as $H$ and vertical as $V$, then there are $H$ copies of the distance between each pair of adjacent vertical fences, and vice versa. This means we can store all edges in $N+M$ memory, and similarly iterate over them in that time complexity. First sort to prepare for Kruskal's.

If we are on some edge, then we'll remove try to remove all copies of that edge (either $H$ copies or $V$ copies) in the corresponding row or column. The number of copies is pretty easy to find; $V+1-$# of columns removed (if you're trying to remove a row) or $H+1-$# of rows removed (if you're removing a column). Also note that for the MST we must remove at least one row and one column so take that into consideration. $O((N+M)log(N+M))$, and my first plat problem!