# USACO Plat 2018 Dec

## 1. Balance Beam
Drawing from Markov chains: we repeatedly set $f(x):=\max(f(x),{{f(x-1)+f(x+1)}\over{2}})$ until the matrix reaches equilibrium.

It turns out that by mapping the points $(i,f(i))$ and finding the upper hull, we can simply translate each point vertically onto the hull to get the answer.

It's clear that the upper hull is the optimal answer, but it may be less trivial to see why it's always possible to apply the aforementioned operation to translate all points onto the hull. Consider a line segment on the hull between the x-coordinates $i$ and $j$. The segment $[i,j]$ is at equilibrium if and only if all points with x-coordinates $\in[i,j]$ are collinear. So it's now easy to see that the operation will always work until these points are collinear, so it's always possible to translate points onto the upper hull.

So the solution is calculated in $O(N)$.

## 3. The Cow Gathering
While possible, greedily remove leaves that can be removed to see if there exists an ordering.

Suppose there does. Then root the tree arbitrarily, and look at all constraints of the form $a$ must leave before $b$. If $a$ is not an ancestor of $b$, then all cows in the subtree of $a$ cannot be last. If $a$ is an ancestor of $b$, then only cows in the subtree of $c$ ($c$ is the child of $a$ that is an ancestor of $b$) can be last.

Consider all constraints of the second type. We find the deepest node $c$ and dfs into its subtree while adhering to all constraints of the first type. All nodes visited in this dfs can be last, and all unvisited nodes can't.

Time complexity: $O(NlogN)$ because binary lifting to check if $a$ is an ancestor of $b$.