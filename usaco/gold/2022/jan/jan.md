# USACO Gold 2022 January

## 1. Drought
The problem mentions two cases: $N$ is even or $N$ is odd. Start with $N$ is even because you can only affect pairs.

If you can get all cows to the same hunger level, then you can also get them all to a hunger level of $0$. To find out whether this is possible for a given sequence of hunger levels, iterate left to right (starting from the second cow), and greedily subtract from the pair containing this as the second cow until the previous cow has a hunger level of $0$. Then, it works if the last cow's hunger level is also $0$ after the process. 

So define $dp[i][j]$ as the amount of ways for the $ith$ cow to have a hunger level of $j$ when following the aforementioned process. Then, $dp[i][j]$ equals the sum of all $dp[i-1][k]$ such that $k+j\le{h_i}$, or ${\sum\limits^{h_i-j}_{k=0}} dp[i-1][k]$. It is critical to realize you can use prefix sums to speed this up from $O(N(max h_i)^2)$ to $O(N(max h_i))$; I spent a considerable amount of time trying to optimize the wrong part of the problem.

When $N$ is odd, we can observe that if we can get all cows to the same hunger level $H$, then it is impossible to get them to any $H$. This means we want to calculate the answer for all $H$ independently (by use of the above dp) and add them up, which takes $O(N(max h_i)^2)$ because each individual dp takes $O(N(\max{h_i}))$.

## 2. Farm Updates
Another case of simulating the process, then backtracking in reverse order. The problem says that roads can only be added between two active farms, so once farms become inactive then they will never become active again.

Basically, if we go in reverse then we want to find the earliest time that each farm becomes active. The reason this is easier to do is because active farms have priority over inactive farms; if there is just one active farm in a component then all farms in the component become active.

So our queries can be remapped to the following:
 - Deactivate: Activate this farm and all farms in its component (if the current node is inactive).
 - Add road: Remove the road. Note we don't actually have to deal with this query. The road must be between two active farms, meaning that when we bump into the query it will just be removing a road from a component fully of active farms. Clearly, this should not affect any future queries. 
 - Remove road: Add the road between the given $X$ and $Y$, and if either node is active (and the other node's component isn't active) then make the other component active.

We only activate inactive components, so we consider each node only one time. Thus, the runtime is $O(N+Q)$.