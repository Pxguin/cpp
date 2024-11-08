# USACO Gold 2021 January

## 1. Uddered But Not Herd

The constraints in the scoring means that $N \le 20$ in all cases.

Given a cowphabet, the answer for string $s$ is the amount of adjacent inversions. If the cowphabet is $abc$, then the answer is the amount of strings $ba+cb+ca$. Let us run bitmask dp, then the answer for subset $i$ is the amount of adjacent inversions between all letters in subset $i$. It runs in $O(2^N*N^2)$.

Note that this is different as storing $dp[i]$ as the min amount of moos for string $s$, when restricted to the letters in subset $i$. Storing the inversions will always work, because given a subset $i$, if we append another character to the back of subset $i$, then it contributes the same amount to the answer no matter the order of subset $i$.

## 2. Telephone

ok so I solved it with Dijkstra, by default there are $N^2$ edges but this can be reduced if you just take the closest cow of each breed (both on left and right side) to every cow, so there are only $NK$ edges. Because you only traverse to the closest cow, say breed $i$, then you have to set $S_{ii}$ to true (breed $i$ communicates with breed $i$). This works because edge weights are distances between cows, so you can traverse from cow $1$ to $2$, and then from $2$ to $3$, and it is the same as going from $1$ to $3$. It takes $O(NKlogN)$, although the official editorial has a $0/1$ BFS solution running only in $O(NK)$ (you can transmit a message left or right, which is weight $1$, or have the current cow receive it, which is weight $0$).

## 3. Dance Mooves

Following the silver version, build a directed edge from $a$ to $b$ if after $K$ swaps a cow at position $a$ goes to position $b$. While going to position $b$ it may go to intermediate positions so store these in a set/vector $S[i]$. We end up with a functional graph composed solely of cycles. 

If $M$ is divisible by $K$ then we can figure out how many nodes we traverse from each node in the graph (simplified to the minimum of the cycle length and $M/K$). Then the answer for a cow is the size of the union of all $S[i]$ on the path it traverses (done using multiset or frequency array). By maintaining a sliding window we can efficiently find the answer for every cow in the cycle.

If $M$ isn't divisible by $K$ then we'll simulate the first $M mod K$ steps then continue from there. Note that when taking the union of all $S[i]$ on the path of node $j$, we also have the consider the positions that $j$ goes to in the first $M mod K$ swaps. Similar to the silver version, this algorithm runs in $O(N+K)$.

Note: if you wanna save memory there's places in my solution where you can reuse arrays (I did this in an early solution draft by having one array serve as the position, visited, and answer arrays) but for clarity they are separated.