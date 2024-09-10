# USACO Gold 2021 January

## 1. Uddered But Not Herd

The constraints in the scoring means that $N \le 20$ in all cases.

Given a cowphabet, the answer for string $s$ is the amount of adjacent inversions.
If the cowphabet is $abc$, then the answer is the amount of strings $ba+cb+ca$.
Let us run bitmask dp, then the answer for subset $i$ is the amount of adjacent inversions between all letters in subset $i$.

Note that this is different as storing $dp[i]$ as the min amount of moos for string $s$, when restricted to the letters in subset $i$.
Storing the inversions will always work, because given a subset $i$, if we append another character to the back of subset $i$, then it contributes the same amount to the answer no matter the order of subset $i$.

## 2. Telephone

hold on