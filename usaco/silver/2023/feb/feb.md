# USACO 2023 Feb

## 1. Bakery
Denote $r_c$ as the amount of moonies spent on reducing cookies and similarly for $r_m$. A friend is satisfied if $a_i(t_c-r_c)+b_i(t_m-r_m)\le{c_i}$. We can see that if we binary search on the total number of moonies spent, $x$, then $r_m=x-r_c$. Thus we can transform the inequality to find a constraint on $r_c$ for each friend, and check if there exists a point satisfying all these constraints. This yields an algorithm of $O(Nlog(t_c+t_m))$ complexity.

Detailed explanation: transform to $a_i(t_c-r_c)+b_i(t_m-(x-r_c))\le{c_i}$. This simplifies to $r_c(b-a)\le{t-a_it_c-b_it_m+b_ix}$. Therefore:

If $b>a$ then $r_c\le{\lfloor(t-a_it_c-b_it_m+b_ix)/(b-a)\rfloor}$.<br>
If $a>b$ then $r_c\ge{\lceil(t-a_it_c-b_it_m+b_ix)/(b-a)\rceil}$.<br>
If $b=a$ then the equation becomes $0\le{t-a_it_c-b_it_m+b_ix}$, so if the right hand side is less than zero then there are no solutions; otherwise, there are infinitely many solutions.<br>
Also, by default, $max(0,x-m+1)\le{r_c}\le{min(x,c-1)}$.

## 2. Cow-libi
Really, the only grazings we care about for each cow are these two: the closest one in time that is earlier than the alibi, and the closest one in time that is later. This is because if a cow can reach both these grazings, then they can reach all the grazings because it is guaranteed that a cow can reach all grazings in the given order. After sorting it takes $O((G+N)logG)$.

## 3. Moo Route II
The algorithm is somewhat of an anomaly between BFS and Dijkstra (I would know Dijkstra before solving this problem). First, add the layover time to each flight's destination time so we can ignore layovers. We can store the minimum time to reach each node, so start at node $1$. If we sort the edges by time, then the set of edges that can be traversed is simply a suffix of the edge list. Update the minimum distance for each of these nodes (if a new minimum distance is detected, then add it to the queue; an unordered set also works fine) and then remove all these edges so we don't have to consider them again. So the achieved runtime is $O(MlogM+N)$.