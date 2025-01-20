# NEERC Finals 2022

## F. Fancy Stack
It's certainly not the best solution (because I go backwards for the dp instead of forwards, which complicates things), but it does work out in the end. 

Let $dp[i][j]$ be the amount of ways to build a stack with blocks $[i,N]$ given that we are missing $j$ blocks in array $a$ (relative to array $b$). A simpler way to think about this is that $j$ represents how many blocks we have put in array $b$, so the rest of the blocks are in array $a$. My $j$ is the difference between the two sizes of the arrays ($|b|-|a|$).

First, assume all blocks are distinct. We can either add this block to array $b$ or add it to array $a$, so do dp transitions as follows.

In the case that blocks can have equal size, we'll group blocks by size, and only allow ourselves to add the earliest block (by index) in each group to array $b$. Additionally, we need an extra dimension in our dp array: $dp[i][j][k=0/1]$ where $k$ represents if the top of the current stack is in array $a$ or not. The reason for this is that if we're in a group of sizes $s$, and we want to add the earliest block in the group to array $b$ (the top of the stack), then the block directly below that (which is in array $a$) cannot have size $s$ as well. 

We can add entire groups to the current stack with some combinatorics. It's a simple modification of the original dp solution. Following from the above, if we want to add a block in the group to array $b$, then we need to make sure we don't assign the slot directly below it to a block in the same group.

At the end, return $dp[0][0][1]$. Time complexity: $O(N^2)$ with a decent constant factor.