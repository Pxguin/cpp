# USACO Gold 2022 January

## 2. Farm Updates

Another case of simulating the process, then backtracking in reverse order. The problem says that roads can only be added between two active farms, so once farms become inactive then they will never become active again.

Basically, if we go in reverse then we want to find the earliest time that each farm becomes active. The reason this is easier to do is because active farms have priority over inactive farms; if there is just one active farm in a component then all farms in the component become active.

So our queries can be remapped to the following:
 - Deactivate: Activate this farm and all farms in its component (if the current node is inactive).
 - Add road: Remove the road. Note we don't actually have to deal with this query. The road must be between two active farms, meaning that when we bump into the query it will just be removing a road from a component fully of active farms. Clearly, this should not affect any future queries. 
 - Remove road: Add the road between the given $X$ and $Y$, and if either node is active (and the other node's component isn't active) then make the other component active.

We only activate inactive components, so we consider each node only one time. Thus, the runtime is $O(N+Q)$.