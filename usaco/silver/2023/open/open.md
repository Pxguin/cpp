# USACO Silver 2023 US Open

## 1. Milk Sum

To get the maximum amount of milk, we should unhook the machines from smallest to largest milk production.
 - So first unhook the smallest $a_i$, then the second smallest $a_i$... and so on.

To deal with each of the $Q$ queries, we want to efficiently change the value, sort the cows, and calculate the answer. Naively it takes $O((N+NQ)logN)$, but can be sped up if we observe that when we move the cow to a new location it shifts a block of cows right by one or left by one. So if cows $b_i,b_{i+1}...b_j$ are moved, the milk production for those cows changes by $\pm ({a_{b_i}+a_{b_{i+1}}+...+a_{b_j}})$ (due to how the milking function works); we can store all these values with prefix sums. The total runtime is $O(NlogN+Q)$.

## 2. Field Day

Once you realize that the farthest from a team is the closest to the inverse of that team, the problem becomes very easy. Then we can just do a multisource BFS with each team as a source and all $2^C$ bitmasks as nodes. Two bitmasks are connected by an edge if they differ by one bit.

The (slightly more difficult) solution in my code is basically the same thing as the multisource BFS, but instead you try individually flipping every bit across every bitmask with for loops.

The runtime is $O(2^C*C+N)$.

## 3. Pareidolia

I tried this problem for the first time in last year December (2022) and failed, tried again in February this year (2023) and failed again (but with more progress); now I'm glad to say that I have improved enough to be able to complete this problem (still with a bit of struggle, as I reworked my entire solution twice before implementation). This in my opinion is a very difficult problem for silver, or at least just a very difficult problem for me. 

Let's compute the answer by fixing a start point $i$, and for every $i$ find the sum of $B(s)$ over all strings beginning at $i$. To do this, we need to find for every start point $i$ the "bessie" in $[i,|t|]$ with the earliest endpoint (the 'e'). This is the hardest part of the problem (I'll cover how to do it later).

Then we can use a dp-ish relationship to calculate our answer. If we iterate backwards, then if at index $i$ we find a "bessie" with an earlier endpoint (denoted $E$, 0-indexed), then $dp[i] = dp[E+1]+(N-E)$ (it makes more sense looking at some test cases; $(N-E)$ is the amount of new "bessies" we add). If there is no new "bessie" with an earlier endpoint, then $dp[i] = dp[i+1]$.

Back to finding the "bessie" with the minimum endpoint for all $i$. We can iterate backwards and store an array with all characters of "bessie" in it, where each index represents the minimum endpoint if we have found all characters from the end of "bessie" to this one.

Time complexity is $O(|t|*|s|)$, where $|s|$ is the length of the string we are looking for (which, in this case, is "bessie"). 