# CSES DP

## Dice Combinations
If we call $dp[i]$ the total number of ways to get a sum of $i$, then add $dp[i]$ to $dp[i+j|{j\in\set{1,2,3,4,5,6}}]$, because we can roll anything from $1$ to $6$. There are $O(N)$ states and $6$ possible dice rolls, so $O(N)$ runtime.

## Minimizing Coins
Instead let $dp[i]$ be the minimum amount of coins needed construct a sum $i$. There are $X$ states and $N$ transitions for a total complexity of $O(NX)$.

## Coin Combinations I
We want to count the number of unordered ways to produce a sum of $x$. So let $dp[i]$ denote this value, and then we can transition to any $dp[i+c_i]$. So, $O(NX)$ runtime again.

## Coin Combinations II
Now we want the ordered ways. In the last program, we iterated over the dp values and then the coins. If we first iterate over the coins and then the dp values, then we can ensure that when we will construct the sum from smallest coin value to largest coin value, and thus we don't overcount any combinations. $O(NX)$ as usual.

## Removing Digits
Let $dp[i]$ be the minimum amount of removals to get the digit $i$. Start from $N$ and iterate in descending order; $dp[N]=0$. Then try removing each digit for each $i$. At the end, return $dp[0]$. So it's $O(N)$.

## Grid Paths
$dp[i][j]$ = the number of paths to row $i$, column $j$. For cell $(i,j)$ we can go to cells $(i+1,j)$ or $(i,j+1)$ (if possible). So $dp[i+1][j]\mathrel{{+}{=}}dp[i][j]$ and $dp[i][j+1]\mathrel{{+}{=}}dp[i][j]$. The answer is $dp[N][N]$. Transitions are $O(1)$ so the overall time complexity is $O(N^2)$.

## Book Shop
This is quite similar to Coin Combinations II. Let $dp[i]$ be the maximum amount of pages given we've spent $i$ dollars. The only difference is that we can buy each book at most once; if we iterate in increasing order of $x$ then we'll overcount (so iterate over $x$ in decreasing order). $O(NX)$.

## Array Description
$dp[i][j]$ is the number of ways to build the array up to index $i$ with last element $j$. It's similar to Bovine Genetics (or the other way around ?) in that the base case for $dp[1][j]$ is brute-forced, but for the rest we can transition to $dp[i][x_i]$ by summing up $dp[i-1][x_i]$, $dp[i-1][x_i-1]$, and $dp[i-1][x_i+1]$. Time complexity is $O(NM)$.

## Counting Towers
Let a small block be a block of width $1$ and a big block be a block of width $2$. At any height, the topmost blocks are either two small blocks or one big block.

So let $dp[i][0/1]$ be the answer for height $i$, given the last block of the tower is two small blocks or one big block. If it's two small blocks, then we can either extend either of the existing small blocks or add a new $1\times{1}$ small block, or add a new big block. For a big block, we can either add two small blocks, a new big block, or extend the current big block.
 - $dp[i+1][0]=4\cdot{dp[i][0]}+dp[i][1]$
 - $dp[i+1][1]=dp[i][0]+2\cdot{dp[i][1]}$

Time complexity: $O(N+T)$; we precalculate queries.

## Edit Distance
$dp[i][j]$ is the minimum cost given we have matched up all $i-1$ characters of the first string and all $j-1$ characters of the second string. We can either delete the character at position $i$, so transition to $dp[i+1][j]$. Replacing character $i$, and then matching $i$ with $j$, gives us the transition to $dp[i+1][j+1]$. Adding a character and matching it with $j$ gives the transition to $dp[i][j+1]$.

Time complexity: $O(NM)$.

## Increasing Subsequence
Find the LIS (longest increasing subsequence). Denote $dp_i$ as the minimum element such that an increasing subsequence of length $i$ ends on that element. Process all $x_i$ from left to right. Then, we want to modify all $dp_j$ satisfying $dp_{j-1}<x_i<dp_j$. $dp$ must be a strictly increasing array, so $x_i$ should update at most one index as well. Binary search on this index for an $O(NlogN)$ runtime.

## Elevator Rides
Do bitmask dp. Define $dp[S]$ as a pair ${R,W}$, where $R$ is the minimum amount of elevator rides for subset $S$. $W$ comes in if there's a tie for $R$, because it denotes the maximum remaining amount of weight that can be added to the elevator.

Do pull dp; for a subset $S$, iterate through all people $i|i\in{S}$. So the candidate for $dp[S]$ comes from $dp[S\setminus{i}]$. Try adding person $i$ to $dp[S\setminus{i}]$ and update the number of elevator rides/maximum weight remaining as necessary, then plug it in as a candidate for $dp[S]$. For $dp[S]$, we obviously want the minimum number of elevator rides first, then if there's a tie we want the maximum remaining weight second. $O(2^N*N)$.