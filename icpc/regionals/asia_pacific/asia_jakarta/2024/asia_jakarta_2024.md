# ICPC ICPCICPC

## G. X Aura
Drawing from shortest-path algorithms such as Bellman-Ford, every single scenario is invalid if there exists a cycle in the graph with negative net cost. If a cycle has positive cost, then we can traverse the cycle in the reverse direction to produce a negative cost. So, all scenarios are possible if all cycles have a net cost of $0$, and otherwise all scenarios are invalid.

Let's assume we want to get from $A$ to $B$, and then back to $A$ (a cycle). For the sake of example, assume that there's two paths $a,b$ going from $A$ to $B$ (with different cost) and a single path from $B$ to $A$ (denoted $c$). Then the two cycles we can make are $ac$ and $bc$. However, because $a$ and $b$ have different costs, then one of $ac$ and $bc$ must have a non-zero cost. Only if $a$ and $b$ have the same cost then both options produce a cost of zero. So, for all cycles to have a cost of zero, all paths from any node $A$ to any node $B$ must have the exact same cost.

We can generalize this to say the above is true if and only if this holds: that for each cell $(x,y)$, all paths from the cell $(1,1)$ to $(x,y)$ have the same cost. This can be checked with a simple DFS from $(1,1)$.

Furthermore, because all paths have the same cost, then we can just answer a query by picking an arbitrary path from $(R_s,C_s)$ to $(R_f,C_f)$. Our path will be $(R_s,C_s)\rightarrow(1,1)\rightarrow(R_f,C_f)$. So let's calculate the distance from $(1,1)$ to all cells $(x,y)$; store this in $dist[x][y]$. The answer for a query is just $-dist[R_s][C_s]+dist[R_f][C_f]$.

Time complexity: $O(RCX+Q)$.

## H. Missing Separators
An $O(N^3)$ dp is as follows: let $dp[i][j]$ denote the maximum amount of words, given that the last word was equal to the substring $[i,j]$. We can then try all $N$ possibilities for the next word, which are of the form $[j+1,k]$. We see that the string $[j+1,k]$ is lexicographically larger than $[i,j]$ for a suffix of $k$ values, and so find the earliest value of $k$, denoted $C_{i,j}$. We can say that all $k\ge{C_{i,j}}$ will also be lex larger.

With this, we can just transition from $dp[i][j]$ to $dp[j+1][C_{i,j}]$, and then transition from $dp[j+1][C_{i,j}]$ to $dp[j+1][C_{i,j}+1]$, then from $dp[j+1][C_{i,j}+1]$ to $dp[j+1][C_{i,j}+2]$, etc. In general, we have the following two transitions:
 - $dp[i][j]\rightarrow{dp[j+1][C_{i,j}]}$
 - $dp[i][j]\rightarrow{dp[i][j+1]}$

By storing a bit extra information in the dp states, then we can restore all words in the end.

It remains to calculate the $C$ array. This can be done with a dp $lcp_{x,y}$ which computes the length of the LCP for the strings $[x,N]$ and $[y,N]$. With a bit of casework, we can use $lcp_{x,y}$ to find $C_{x,y-1}$.

Time complexity is $O(|S|^2)$.

## I. Microwavable Subsequence
Here's how to calculate the value of $f(x,y)$:
 - Delete all elements from the array except those equal to $x$ or $y$. Let this length of this array be $f_1(x,y)$ and the array itself be $a_1(x,y)$.
 - For each pair of adjacent equal elements, delete one copy from the array.
 - The resulting array is the array corresponding to $f(x,y)$.

To calculate this across all values of $x$ and $y$, we'll simulate all the processes at once. We first sum up all values of $f_1(x,y)$, then subtract the amount of duplicates across all arrays to get to the sum of $f(x,y)$.

Letting $freq_x$ be the amount of occurences of $x$ in the array, the sum of $f_1(x,y)$ is $freq_1(M-1)+freq_2(M-1)+\dots+freq_M(M-1)=N(M-1)$. It's because $f_1(x,y)=freq_x+freq_y$, so if we expand the sum across all pairs $(x,y)$ then each frequency value will appear $M-1$ times.

Now we must subtract values to get to the sum of $f(x,y)$. Consider two "adjacent" values of $x$ in the original array; that is, two indices $i$ and $j$ such that $a_i=a_j=x$ and there exists no other occurence of $x$ in the range $[i+1,j-1]$. For any value $y$ that does not appear in the range $[i+1,j-1]$, then $i$ and $j$ are adjacent in $a_1(x,y)$, and so we must delete one of the two. 

Generalizing, let's consider all "adjacent" values of some $x$, at indices $i$ and $j$, for all $x$. Let the number of distinct values in the range $[i+1,j-1]$ be $D$. Then, $i$ and $j$ will not be adjacent in $a_1(x,y)$ for any of those $D$ values, meaning that they are adjacent in $a_1(x,y)$ for $(M-1)-D$ values of $y$. In those cases, we delete either $i$ or $j$. Therefore, subtract $(M-1)-D$ from the answer. After all subtractions have been done across all valid pairs of $i$ and $j$, then we have gotten our final answer, which is the sum of $f(x,y)$.

The distinct values part is just [CSES - Distinct Values Queries](https://cses.fi/problemset/task/1734). Time complexity is $O(NlogN)$ because we consider at most $N$ ranges.