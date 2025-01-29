# USACO Gold 2022 US Open

## 1. Apple Catching
A cow at position $x_i$ at time $t_i$ can catch an apple $x_j$, $t_j$ if the following holds: $|x_i-x_j|\ge{t_i-t_j}$ where $t_i\ge{t_j}$. If $x_i$ is treated as the x axis and $t_i$ as the y axis, then a cow at $(x_i,t_i)$ can catch any apples satisfying $y-t_i\ge{|x-x_i|}$. Rotate the plane by $-45°$ and scale by $\sqrt{2}$ so that a point at $(x,y)$ becomes $(x+y,y-x)$. Then for a cow at $(x_i,t_i)$, it can catch all apples $(x,y)$ if $x_i\le{x}$ and $t_i\le{y}$.

Iterate over all apples by x and then by y. It can be said that out of all available cows that can catch each apple, the most optimal assignment is to the cow with the greatest $y$ value. In other words, we pick the cow with the strictest $t_i$ constraint. The reason this works is only because it is assumed that we have already assigned all apples that have a lower x and y value compared to this one. The runtime is $O(NlogN)$.

## 2. Pair Programming
The editorial solution > my solution (you should read it)

Given that we're building the final program, at any point we can either incorporate the next instruction of Bessie's or Elsie's program, which indicates a dp. Also, the instructions of type $\times{d}$ affect all variables prior to it, so if we reverse the programs that they will affect everything after it. $dp[i][j]$ can be the amount of distinct outputs given a program consisting of the first $i$ instructions of Bessie's program and the first $j$ of Elsie's program. 

At first, $dp[i][j]=dp[i-1][j]+dp[i][j-1]$. This may overcount $dp[i-1][j-1]$, so we subtract $dp[i-1][j-1]$ if this is the case, which is if when adding the $ith$ and $jth$ instructions to the programs counted by $dp[i-1][j-1]$, adding them in the order $ij$ produces the same output as $ji$. Here I'll cover the cases in which $ij$ produces a <i>different</i> output than $ji$. We can say if $i$ and $j$ are both variables or numbers, then this never happens. Only if $i$ is a variable and $j$ is a number is it possible, or vice versa. I'll assume $i$ is the number. Additionally, to satisfy $ij\ne{ji}$, multiplying by $i$ first should change the coefficient on $j$, which won't be the case if $i$ is the number $1$, or if the previous coefficient in the program was $0$ anyways. The runtime becomes $O(N^2)$.

## 3. Balancing a Tree
The editorial solution is confusing and I don't understand it right now, but it seems much more elegant than my solution.

Binary search on the minimum imbalance $B$. We will then find two ranges for each node $c_i$ and $p_i$. $c_i$ denotes the range of weights that node $i$ can be set to in order to guarantee a valid solution for its subtree. $p_i$ denotes the range of weights that an ancestor of node $i$ can be set to such that a valid solution exists for the subtree of $i$. We then have dp as follows:
 - First, initialize $c_i=[l_i,r_i]$ and $p_i=[\max(0,l_i-B),r_i+B]$.
 - Go through all children $j$ of $i$. Observe that $c_i$ must compromise with all $p_j$, so set it to the intersection of all $p_j$ and the initial range $[l_i,r_i]$. If $c_i$ becomes an empty range, then this $B$ value is impossible.
 - Set $p_i$ to the intersection of all $p_j$ and the initial range $[\max(0,l_i-B),r_i+B]$ by similar reasoning.

If all $c_i$ are nonempty, then the $B$ works. After finding the minimum $B$ we can output it for half credit. From here, $B$ refers to the minimum $B$ and $c_i$ refers to the range for $i$ for the minimum $B$.

Any value in the range specified by $c_0$ is a valid candidate for $w_0$, so we can set $w_0$ to the leftmost point in $c_0$ for convenience. Let the leftmost point in $c_i$ be denoted $C_i$. We can then recursively build the tree as follows: $w_i=\max(C_i,C_j-B)$ for ancestors $j$ of $i$.

This solution has a complexity of $O(Nlog(\max{r_i}))$.