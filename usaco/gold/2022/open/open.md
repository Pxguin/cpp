# USACO Gold 2022 US Open

## 1. Apple Catching
A cow at position $x_i$ at time $t_i$ can catch an apple $x_j$, $t_j$ if the following holds: $|x_i-x_j|\ge{t_i-t_j}$ where $t_i\ge{t_j}$. If $x_i$ is treated as the x axis and $t_i$ as the y axis, then a cow at $(x_i,t_i)$ can catch any apples satisfying $y-t_i\ge{|x-x_i|}$. Rotate the plane by $-45°$ and scale by $\sqrt{2}$ so that a point at $(x,y)$ becomes $(x+y,y-x)$. Then for a cow at $(x_i,t_i)$, it can catch all apples $(x,y)$ if $x_i\le{x}$ and $t_i\le{y}$.

Iterate over all apples by x and then by y. It can be said that out of all available cows that can catch each apple, the most optimal assignment is to the cow with the greatest $y$ value. In other words, we pick the cow with the strictest $t_i$ constraint. The reason this works is only because it is assumed that we have already assigned all apples that have a lower x and y value compared to this one. The runtime is $O(NlogN)$.

## 2. Pair Programming
The editorial solution > my solution (you should read it)

Given that we're building the final program, at any point we can either incorporate the next instruction of Bessie's or Elsie's program, which indicates a dp. Also, the instructions of type $\times{d}$ affect all variables prior to it, so if we reverse the programs that they will affect everything after it. $dp[i][j]$ can be the amount of distinct outputs given a program consisting of the first $i$ instructions of Bessie's program and the first $j$ of Elsie's program. 

At first, $dp[i][j]=dp[i-1][j]+dp[i][j-1]$. This may overcount $dp[i-1][j-1]$, so we subtract $dp[i-1][j-1]$ if this is the case, which is if when adding the $ith$ and $jth$ instructions to the programs counted by $dp[i-1][j-1]$, adding them in the order $ij$ produces a different output than $ji$. We can say if $i$ and $j$ are both variables or numbers, then this never happens. Only if $i$ is a variable and $j$ is a number is it possible, or vice versa. I'll assume $i$ is the variable. Additionally, to satisfy $ij\ne{ji}$, multiplying by $i$ first should change the coefficient on $j$, which won't be the case if $i$ is the number $1$, or if the coefficient of $j$ in the order $ji$ comes out to $0$. The runtime becomes $O(N^2)$.