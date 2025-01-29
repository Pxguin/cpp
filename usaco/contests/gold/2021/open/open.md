# USACO Gold 2021 Open

## 1 - United Cows of Farmer John
Fix each cow as the left of the delegation. Cow $i$ can only be the leader up to the next occurence of $b_i$, so store this as a range. If we do the same by fixing the rightmost leader of the range (call them right side ranges), then we can say that the number of delegations that can be formed with cow $i$ as the left leader (its left side range is $[a,b]$) is equal to the amount of right side ranges $[c,d]$ such that the intersection is $[a,d]$. In other words, $a\ge{c}$, $a\le{d}$, and $b\ge{d}$. Sweep through all ranges sorted by endpoint to fix $a\ge{c}$, then just count the number of ranges with $b\ge{d}$ and subtract the amount of ranges with $a\ge{d}$ with something like a BIT or ordered set. From these operations, the runtime becomes $O(NlogN)$.

## 2 - Portals
Must have spent an extra pointless two hours because I didn't read the problem carefully, but whatever.

The problem asks you to visit every <i>location</i>. This is equivalent to saying you must reach $p_{v,1},p_{v,2},p_{v,3},p_{v,4}$ for all vertices $p_v$, which implies that we can reach every portal from every other portal.

So, let's build a graph with vertices as portals, with an edge between $p_{v,1}$ and $p_{v,2}$, and another one between $p_{v,3}$ and $p_{v,4}$. Then we can reach all locations from all locations if a spanning tree exists.

To account for being able to permute portals, we would infer that we want to modify the graph and then find a min spanning tree. So let's make a few key observations:
 - Each portal appears in exactly 2 adjacency lists. This means that the original, default graph should be made up of multiple disjoint simple cycles (you can try it on the sample data).
 - This means that if two nodes are in the same cycle then there's always two ways to reach the second node from the first.
 - Therefore, we can just draw an edge costing $c_i$ from $p_{v,1}$ to $p_{v,3}$, and a similar one from $p_{v,2}$ to $p_{v,4}$. There is no need to remove the previous edges because there's always another way to reach $p_{v,2}$ from $p_{v,1}$ and to reach $p_{v,4}$ from $p_{v,3}$. Note that we only have to consider one of the edges when building the MST as we won't remove the previous edges. As a result, the two cycles will now be connected.
 - This same logic works for all $p_i$.
Runtime: $O(NlogN)$.

## 3 - Permutation
The first three points form a triangle. Call the strictest triangle enclosing all points as the bounding triangle. After this, for each element $i$ from $4\dots{N}$, we do one of the following: either add it inside the current bounding triangle or outside the bounding triangle, thus enlarging it. If we add it inside the current triangle, exactly three segments will always be drawn. But if we draw it outside, it may or may not form three segments. We can check if it's possible with the following method: we have triangle $\Delta{ABC}$ and are trying to add point $D$. It's doable if the line segment from $D$ to any vertice of the triangle doesn't intersect the line segment formed by the other two vertices. For example, $\overline{DC}$ doesn't intersect $\overline{AB}$.

These transitions lend themselves to dp. Let $dp[T][i]$ be the amount of ways to pick a permutation of length $i$ with bounding triangle $T$. $i$ will at most be the amount of points contained inside triangle $T$, which we will denote $M_T$. Then for the transitions, we either add a point inside or outside $T$. If we add it inside, then $dp[T][i+1]\mathrel{{+}{=}}dp[T][i]*(M_T-i)$ because we have $M_T-i$ points to choose from. For all points that can be added outside $T$, denote the new bounding triangle formed as $T'$. In this case, $dp[T'][i+1]\mathrel{{+}{=}}dp[T][i]$. 

The only remaining issue is in what order we iterate over the triangles for our dp. To solve this, draw a hypothetical edge from triangle $A$ to $B$ if there exists a point outside $A$ such that when adding it, the new bounding triangle becomes $B$. The resulting graph is a DAG, and the solution is to process it in the topological sort of the graph. Or more simply, process by increasing triangle area. In summary, there are $O(N^4)$ states and $O(N)$ transitions so an $O(N^5)$ algorithm (which in this case, runs very quickly).