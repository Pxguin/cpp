# USACO Gold 2014 January

## 1. Cow Curling
WLOG assume that we are counting # of red triangles containing blue points.

Any red triangle is contained inside the convex hull of red points. The converse also holds. So, find the convex hull of all red points in $O(NlogN)$.

Now we have to figure out whether each blue point is inside the hull or not. We can separate the hull into the lower and upper hulls, then run sweep line to figure out the min and max y coordinates of the hull at any given x coordinate. That will answer all queries in $O(N)$.

Therefore, the solution runs in $O(NlogN)$.

## 3. Ski Course Rating

Simulating in $O((MN)^2)$ requires a flood fill from every starting position, combined with binary search. In fact, this is pretty much just the silver version of the problem. To speed it up a bit notice the repetition involved in the flood fill. If we treat this as a weighted graph and simply add edges in increasing order of weight, then we only have to consider $4MN$ edges. Well what am I saying, basically just use DSU to store the number of starting points in each component. Merge components as necessary and if at any point the size of a component exceeds $T$ then just add to the answer. Also I originally missed this but $T=1$ is a special edge case that doesn't show up in the official test data (thanks usaco guide). It runs in $O(MNlogMN+MN\alpha{(MN)})$ where the log is from sorting edges by weight.