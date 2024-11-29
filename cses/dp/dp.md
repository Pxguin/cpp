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

## Elevator Rides
Do bitmask dp. Define $dp[S]$ as a pair ${R,W}$, where $R$ is the minimum amount of elevator rides for subset $S$. $W$ comes in if there's a tie for $R$, because it denotes the maximum remaining amount of weight that can be added to the elevator.

Do pull dp; for a subset $S$, iterate through all people $i|i\in{S}$. So the candidate for $dp[S]$ comes from $dp[S\setminus{i}]$. Try adding person $i$ to $dp[S\setminus{i}]$ and update the number of elevator rides/maximum weight remaining as necessary, then plug it in as a candidate for $dp[S]$. For $dp[S]$, we obviously want the minimum number of elevator rides first, then if there's a tie we want the maximum remaining weight second. $O(2^N*N)$.