# USACO Gold 2024 January

## 1. Walking in Manhattan
Yeah I solved 90% of this problem in 30 minutes and the other 10% took me like four hours, and debugged a silly typo-caused error for 1 hour. So not entirely sure how hard this problem is; could be anywhere from 2300-2600 on CF imo. Still I think this is an awesome problem.

For simplicity I'll start with subtask 2: $N,Q <= 3000$. If our initial location isn't at an intersection of roads we'll move it there and then find which direction we go in. Also, if this distance is $>= D$, then just backtrack and we have our answer. Otherwise, we should observe that we change directions at the first intersection an odd distance away from our starting intersection, and this pattern continues throughout the path. So, let's find for each road the earliest road such that it's an odd distance away from this one, and then from the starting intersection just follow those indices to build our path. In other words, we have a starting intersection $X$, then we go to the nearest road an odd distance away, $Y$, then repeat for $Y$, etc. until the total distance is $>= D$. Then we can just subtract to get back to $D$ distance traveled. Because each path is at most $2N$ roads, meaning we iterate through $2N$ elements, the total runtime is $O(NQ)$.

To optimize the runtime we should isolate the path into its horizontal and vertical components. We can figure out how many roads we travel in the $H$ and $V$ directions separately, then combine our answers. So if we store separate lists for $H$ and $V$ roads where each road is followed by its nearest odd-distance road, then from any given road we can calculate where we end up if we travel along $X$ roads in the $H/V$ direction from here. Now, observe that multiple roads can have the same nearest odd-distance road, so to break ties we'll take the earliest road and combine the rest into it (this is the single thing that took me 2 hours). From here we'll just binary search on the amount of roads, $X$, and find the lowest $X$ such that the distance traveled is $>= D$. The cow must alternate between $H$ and $V$ roads so we can compute how many roads of each type we walk on. $O(N)$ preprocessing, and an $O(logN)$ binary search with an $O(1)$ check function, so the total runtime is $O(N+QlogN)$.

## 2. Cowmpetency
Either I've gotten a lot better, or this is just easier than the silver version. There's a couple observations necessary to solving this problem:
 - A pair is satisfied if $\max(0\dots{a_i})=\max(0\dots(h_i-1))$. Then, $h_i>\max(0\dots{a_i})$.
 - So if there exist $a_i,a_j$ with $h_i=h_j$, then we only care about the smaller $a$ because it's more strict.
 - If there exist two ranges that overlap at a single endpoint, then it's fine. But if there exist two overlapping ranges (sharing area), then there is no solution.

So after removing excess pairs, we basically have $Q'$ disjoint $[a_i,h_i)$ ranges. Iterate over $a_i$ in increasing order and define $dp[i][c]$ as the amount of ways to construct an array up to and including index $i$, with maximum score $c$.
 - $dp[i+1][c]=dp[i][c]*c$
 - $dp[i+1][c]={\sum_{j=1}^{c-1}dp[i-1][j]}$

These are the two main transitions. Either we increase the maximum $c$ or we don't increase it. We're free to increase it if $i$ isn't in a range, but if $i$ is in an $[a_i,h_i)$ range we must maintain a constant max, so only use the first transition. If $i$ is an $h_i$ value, then it must be a new max, so use the second transition only. This takes $O(NC)$, but can be reduced down to $O(QClogC)$.

We really only care about the $a_i$ and $h_i$ values. So we transition from $dp[h_{i-1}]$ to $dp[a_i]$, and from $dp[a_i]$ to $dp[h_i]$. The first transition is as follows:
 - $dp[a_i][c]={\sum_{j=1}^{c-1}(dp[h_{i-1}][j]*(c^g-(c-1)^g))}+dp[h_{i-1}][c]*c$ where $g=a_i-h_{i-1}$. We can change the max as we please.

It's easier to transition from $a_i$ to $h_i-1$ and then from $h_i-1$ to $h_i$, so I'll list them separately.
 - $dp[h_i-1][c]=dp[a_i][c]*c^g$; $g=h_i-1-a_i$. We must maintain the max of $c$.
 - $dp[h_i][c]={\sum_{j=1}^{c-1} dp[h_i-1][j]}$. $h_i$ must be a new max.

With prefix sums and binary exponentiation, we can therefore achieve an $O(QClogC)$ runtime.

## 3. Nap Sort
Yeah I don't know how I solved this with shaky logic, but after trying it against some tests I thought it would fail on, I'm pretty sure that it's an ok solution.

The time to sort is defined by the time that the last integer is placed. If this integer isn't in Bessie's pile, then it takes $a_N$ time (assume elements of $a$ are sorted). Otherwise, if Bessie's pile is of size $B$, then it takes $B(B+1)/2$ time. The goal is to find the minimum $B$ such that a valid sort still exists. 

First, just iterate over all $B$. We force the last integer to be placed at time $B(B+1)/2$, which may cause contradictions with the number before it. Call $T$ the time that the last integer was placed. There's a contradiction if $a_{N-1}>T$ and $a_{N-1}=a_N$, or $a_{N-1}\ne{a_n}$ and $a_{N-1}\ge{T}$. If any of these are the case, then we're forced to add $a_{N-1}$ to Bessie's pile to ensure it gets added before time $T$. Update $T$, and check for the next integer; continue repeating this until Bessie's pile overflows (in which case this $B$ doesn't work) or there are no contradictions left. I'll assume the latter.

If there are no contradictions left, then this $B$ simply works. Let's say that we have $L$ integers left in Bessie's pile, added at times $t_1,t_2,\dots,t_L$. Then, it's always possible to assign $t_i$ such that the remaining array is sorted (explanation later). This means that it really just depends on getting rid of the contradictions in the beginning, so if $B$ works then $B+1$ works. Binary search on $B$ for a final complexity of $O(NlogN)$.

Here an example greedy solution: assign $t_i$ in reverse order (starting from $t_L$), with $t_i$ being assigned to the largest remaining $a_j$ satisfying $a_j<{t_i}$. If no such $a_j$ exists, then assign it to the first element. If this is already assigned, shift that to the right by one.

