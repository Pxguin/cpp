# CSES Additional Problems

## Even Outdegree Edges
First, there must be an even number of edges in every connected component. Then the problem can very easily be solved greedily for a rooted tree (however, the degree of the root may not be even in the end). If we arbitrarily direct each edge not part of the spanning tree and then solve the problem on the spanning tree, then we ensure that all but the root has an even outdegree. However, the root must too as a byproduct, because if the number of edges is even and all other nodes have even outdegree, then there must be an even number of edges remaining for the root. We can thus calculate this in $O(N+M)$.

## Multiplication Table
Binary search on the median. To check, we make sure our value X is >= half of the values in the table.
Do to this, iterate over every row of the table and count the number of values that X is greater than or equal to with some basic math.
(If we are on row i, then X is greater than min(X/i, n) values)

## Advertisement
For every height, find the largest width of the advertisement assuming this is the minimum height in the ad (then take the maximum).
 - This implies finding the nearest smallest values on the right and left side of each value, which can be done with a stack.
The max width of the ad for this height will be right-left+1.

## Maximum Building I
This builds on the Advertisement problem. We can fix the bottom row and then calculate the maximum area like this similarly to the aforementioned problem.

## Xor Pyramid
I'll update when I prove the stuff used. For now we want to find how many times each element on the bottom row is xored by the time you reach the top element, which are the binomial coefficients for $n-1$. Proof: Consider two cells with values $A\oplus{B}$ and $B\oplus{C}$. Then the value above it will have value $A\oplus{B}\oplus{B}\oplus{C}$, i.e. the union of the two values below it. So, in this fashion, the amount of times a cell $k$ is xored is the amount of unique paths from the topmost cell to cell $k$, provided that you can only go from a cell to the two cells directly below it. There are ${n-1}\choose{k}$ ways to do this - you have $n-1$ total edges and want to select a subset of $k$ edges going right, defaulting the rest $n-1-k$ edges to going left.

We only care about the parity of the binomial coefficients and ${n\choose{k}} = {{n!}\over{k!(n-k)!}}$, so if the largest power of 2 in $n!$ (i.e. prime factorization) is $\le$ the sum of the powers in the denominator then the result is odd. If you care it is never possible to have the case $top-bottom < 0$ because you get a fraction, so you can just assume $= 0$. To find the largest power of $2$ in $x!$ note $x! = x*(x-1)!$ so it is the sum of the answer of $(x-1)!$ and $x$ (use prefix sums). The alternate solution in my code relies on [this link](https://math.stackexchange.com/questions/11002/cn-p-even-or-odd) ok so update later when I actually understand all of that (I probably won't). $O(N)$ btw.

## Empty String
Define $dp[i][j]$ as the minimum amount of operations to empty the string $i...j$. The dp transition on ranges will be as follows: for some range $[i,j]$, we'll try to pair up the first character in it - assume a matching character is at $k$, then you'll combine the answers for the ranges $[i,k]$ and $[k+1,j]$ to get answers for $[i,j]$. 

It may be the case that the range $[i,k] = [i,j]$, in which case $dp[i][j]=dp[i+1][k-1]$ (although $i+1>k-1$ if $i$ and $k$ are adjacent, so make sure to properly set base cases, that is, $dp[i][j]=1$ for all $i>j$). Otherwise, you know that you have ${k-i+1}\over{2}$ pairs to erase from the first range (which can be removed in $dp[i][k]$ ways), and ${j-k}\over{2}$ pairs in the second range (which can be removed in $dp[k+1][j]$ ways). In total, you have to remove ${j-i+1}\over{2}$ pairs. So the total number of ways is $dp[i][k]*dp[k+1][j]*{{(j-i+1)/2}\choose{(k-i+1)/2}}$, and add that to $dp[i][j]$. 

In total, the runtime is $O(N^3)$.

## Stick Divisions
Very AtCoder type problem (that I couldn't solve by myself). Start out with all $N$ sticks, and repeatedly combine the two sticks with the smallest length until there's only one stick remaining. We can prove this fact as follows: the answer must be the sum of $x_id_i$ for all $d_i$, with $x_i$ as some coefficient. If we extract all these $x_i$, then by repeatedly combining any two identical $x_i$ with $x_i-1$, we should end up with one $0$ at the end. This is to say that we initially set all $x_i=0$. When we combine two sticks, we increase the $x_i$ of all sticks combined inside those two sticks. So it should be clear that we want to constantly combine the sticks with the smallest lengths. It's never the case that we backtrack and combine substicks of our current sticks, because if that's the case then the substicks should already have been combined into one stick at any earlier point in time. This gives us an $O(NlogN)$ algorithm when using a priority queue.

## Coding Company
Sort all coders by $a_i$, so that the penalty for a group can be retrieved by looking only at the two endpoints of the subsequence. If the first coder in a team is $i$ and the last is $j$, then the penalty is $a_j-a_i$. This is essentially $(a_{i+1}-a_i)+(a_{i+2}-a_{i+1})+\dots+(a_j-a_{j-1})$.

Let $dp[i][j][k]$ be the answer for the first $i$ people, given that the current penalty is $j$ and we have $k$ unfinished teams. Let $d=a_{i+1}-a{i}$.
 - $dp[i+1][j+dk][k]\mathrel{{+}{=}}k\cdot{dp[i][j][k]}$ (add the $(i+1)th$ person to any existing team; $k$ ways to do this).
 - $dp[i+1][j+dk][k+1]\mathrel{{+}{=}}dp[i][j][k]$ (start a new team with the $(i+1)th$ person, $1$ way to do this).
 - $dp[i+1][j+dk][k-1]\mathrel{{+}{=}}k\cdot{dp[i][j][k]}$ (add the $(i+1)th$ person to an existing team, and then end that team).
 - $dp[i+1][j+dk][k]\mathrel{{+}{=}}dp[i][j][k]$ (start and end a team with the $(i+1)th$ person; i.e. put it into its own solo team).

Time complexity is $O(N^2X)$. A faster way to solve this problem is on [USACO guide](https://usaco.guide/problems/cses-1665-coding-company/solution). Essentially, the penalty is $a_j-a_i$ so it lets the cost at $i$ be $-a_i$ and the cost at $j$ be $a_j$ (and then does a knapsack, also in $O(N^2X)$).