# USACO Gold 2023 Feb

## 1. Equal Sum Subarrays
Fix $i$. For two subarrays to have equal sum, one of them must contain $i$, and one of them must not contain $i$. Otherwise, the sum of both subarrays change by the same amount. So we can check for each $i$ in $O(N^2logN^2)$ by grouping all ranges by the aforementioned property, sorting each group, and then using 2p to calculate the answer. This times out, but we can reduce the check for each $i$ to $O(N^2)$ if we sort all ranges by sum in the very beginning. So, the time complexity is $O(N^3)$.

## 2. Fertilizing Pastures
Well, I got bullied pretty hard by the greedy subproblem and the debugging process.

To minimize the time, once we're in a subtree then we can't leave the subtree until every node has been visited; leaving the subtree will <b>strictly</b> worsen the answer.

So create two dp arrays: the first is $time[i][v=0/1]$ which is the minimum amount of time if we start at node $i$ and end back at $i$ (if $c=0$) or can end anywhere (if $c=1$). The second is $cost[i][v=0/1]$ which stores the same thing, but for fertilizer cost.

### $T=0$
The only variables we need to calculate in order to solve this subtask are $time[i][0]$ and $cost[i][0]$.

$time[i][0]$ is by far the easiest to calculate. It's the sum of $time[i][c]+2$ for children $c$ of $i$. More simply, $time[i][0]=2(sz_i-1)$, where $sz_i$ is the size of the subtree of $i$. This is because we traverse every edge twice in the optimal ordering, and there are $sz_i-1$ edges in this subtree.

Calculating $cost[i][0]$ is harder, and requires a greedy strategy. To calculate for $i$, we have to decide on some ordering $c_1,c_2,...$ to traverse the children of $i$. The cost of traversing the subtree of $c$ starting from time $t$ is equal to $cost[c][0]+sum_c*t$, $sum_c$ denoting the sum of all $a_i$ in the subtree of $c$. 

Letting the set of children visited before child $c$ be $S$, we can calculate $t$ as $1+(\sum_{j\in{S}}{time[j][0]+2})$, which simplifies to $1+(\sum_{j\in{S}}{2*sz_j})$. Thus, the cost of traversing child $c$ in this ordering is $cost[c][0]+sum_c*(1+(\sum_{j\in{S}}{2*sz_j}))$. 

Most of the terms after expansion are independent of the order of the children, so after dropping these terms our goal is to minimize the sum of $sum_c*(\sum_{j\in{S}}{sz_j})$ across all $c$. So following this expression, for two children $i$ and $j$, it's optimal to order $i$ before $j$ if $(sum_i)(0)+(sum_j)(sz_i)\le(sum_j)(0)+(sum_i)(sz_j)$. We see that post-simplication we get the inequality ${sz_i\over{sum_i}}\le{sz_j\over{sum_j}}$. This holds for all adjacent pairs $i$ and $j$ because we can always simplify the equation to the above, and the resulting inequality is also transitive. So, the greedy strategy is to traverse children $c$ in non-decreasing order of ${sz_c}\over{sum_c}$.

Now that we have this ordering, it's easy to calculate $cost[i][0]$ with the provided equation.

### $T=1$
There's two new variables, $time[i][1]$ and $cost[i][1]$.

We see that to minimize the time needed to traverse $i$, we want to add up $time[c][0]$ (min time to traverse and return to $c$) for all but one of the children, and $time[c][1]$ (min time to traverse and stop anywhere) for the remaining child. For a child $c$, the time saved by not having to return to node $c$ is precisely $time[c][1]-time[c][0]$, so the child that we take the value of $time[c][1]$ of (and thus the child we traverse last) will be the one with the maximum value of $time[c][1]-time[c][0]$.

Now for $cost[i][1]$. If multiple children have the same maximum $time[c][1]-time[c][0]$, then there's actually no greedy strategy to pick one, so we have to try traversing each of them last. Let the set of these candidate children be $C$.

This is done by taking the default $sz\over{sum}$ ordering of the children, and trying to move each of the children in $C$ to the end of the ordering. The cost for the default ordering is kept in $cost[i][0]$. To try moving child $i$ to the end, we first subtract the term that it contributed to $cost[i][0]$. This child also contributes $2*sz_i*sum_c$ for all children $c$ after $i$, so use suffix sums to subtract that amount. We can then add child $c$ back to the end of the new ordering, and get a candidate answer for $cost[i][1]$.

Time complexity is $O(NlogN)$. I could not figure out the $sz\over{sum}$ greedy ordering by myself, but all else was done by myself.