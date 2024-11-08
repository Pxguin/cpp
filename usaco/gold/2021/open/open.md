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