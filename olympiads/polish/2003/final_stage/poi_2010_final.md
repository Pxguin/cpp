# POI 2010 Final Stage Day 1

## 2. Sums
The goal is, how can we reduce $b_i$ to a manageable number? One way is by reducing by $a_0$. If for a sum $x$, $x\equiv{b_i}\pmod{a_0}$ and $x\le{b_i}$, then we can simply add $k\cdot{a_0}$ to $x$ in order to get a sum of $b_i$.

Now the goal is to calculate the minimum sum equivalent to $i\pmod{a_0}$ for $0\le{i}<a_0$. Knapsack is the easiest way, but I chose Dijkstra because the runtime is more heuristic than a fixed dp, especially because the asymptotic complexity is roughly $O(NA)$. Another heuristic optimization is to ignore sums that are greater than $10^9$, which is the upper bound for any $b_i$. Using these, this solution fits very comfortably in the time limit.

With Dijkstra, the time complexity is $O(NAlogA)$.