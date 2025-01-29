# USACO Gold 2023 January

## 1. Find and Replace
Servers are down which is pretty frustrating, but I'm almost definitely sure that my code works (except for MLE maybe because I could not test that).

Build a tree on the strings, where each node corresponds to one of the strings and the children represent what string each of the characters in the string transform into next as a result of operations. 
 - For example, assume there are two operations "a aab" "b cd". The nodes correspond to the strings "a" (starting string), "aab", and "cd". The string "a" is the root, and it points to the string "aab". "aab" has three children, for each of its characters. The first two point to nothing, and the third points to the string "cd", etc.

Like a segment tree, we can store what range of letters in the final string the current node corresponds to, and dfs from the root, and combine segments together in order to get the final $[l,r]$ range. For now, we can store the indices that each segment corresponds to. We have to figure out the actual string that it corresponds to in order to get the answer, but I'll cover that later.

Let $N$ be the amount of operations, $S=\sum{|s|}$, and $M=r-l+1$. The time complexity here is $O(NS+M)$. We have at most $M$ segments, and check at most $NS$ nodes. For each node, we have to look through all its children and see which ones belong to the segment. If the range of letters that it corresponds to lies in the range $[l,r]$, then we add it to the list of segments and stop there. Otherwise, if the range it corresponds to intersects $[l,r]$, then we have to dfs into its subtree. If it has no relation to $[l,r]$, then we don't care about it.

Instead of searching through all children, observe that the amount of children that we will dfs into forms a range, so we can just binary search on the left and right endpoints of the range. By only considering children that are part of the final range, the time complexity is reduced to $O(NlogS+M)$ — we only consider at most a small factor of $N$ nodes. 
 - The reason is as follows: we only dfs further from some node if one of the children for that node intersects $[l,r]$, but isn't contained inside $[l,r]$. There are at most $2$ of these children per node (at the left and right endpoints of the range). Call these children <i>bad</i> nodes.
 - Initially, the range for the root has at most $2$ of these bad children (I'll assume it has 2 of them). This means that when we dfs to each of these children, then we effectively cut that range into two, so these children have at most $1$ bad child. It's easy to see that the amount of these bad nodes is non-increasing as we move further down the tree, so if the current node has only $1$ bad child, then it will never split again. So for those two bad children of the root, we consider a linear amount of nodes in their subtrees. This is precisely $N$, which is the maximum depth of the tree. For each node, we binary search, so the time complexity is $O(NlogS+M)$.

Now we have the segment composition of the final range, and need to turn all the segments into strings. Let $L$ be the number of segments; we can say that the sum of all segments equals to $M$.

There's two methods to try for this: we could traverse the subtree corresponding to each segment to find the string it corresponds to, but each dfs might take $O(N)$ so the complexity of this would be $O(LN+M)$. We could memoize what strings indices correspond to, but this takes a lot of memory. However, the only reason this takes up lots of memory is if there exists an operation that turns a character into another single character, as this doesn't change the size of the string. If all operations turn a character into a string of length $\ge{2}$, then the memory is bounded by a log factor.

We can therefore just compress the tree to get rid of all operations that turn a character into another character. Now each node in the tree has at least two children. We will go with the first dfs solution; therefore, given that we're doing dfs into a subtree of some segment $i$ of length $T$, the worst case is when the number of nodes in the tree is maximized.
 - The tree has $T$ leaves. Worst case is a perfect binary tree which will have $2T-1$ nodes. $\sum{T}=M$, so the time complexity is $O(M+NlogS)$.

Alternatively, go with the memoizing solution. The worst case is when the sum of all segment sizes (string sizes) in the subtree is maximized.
 - Idk what the worst case is, but it is probably a perfect $\sqrt{T}$-ary tree which gives a total string length of $T\sqrt{T}$? Meaning the total time complexity is $O(M\sqrt{M}+NlogS)$. I tried to analyze this and make some stronger data than the test cases, but it always ran as fast as the above solution.

As a consequence, you could avoid storing the indices of the segments altogether, and simply just continue the dfs on those segments (this is assuming that the tree is compressed).

## 2. Lights Off
This problem is so difficult and I don't know how the solve rate by promoters was so high. The solution is quite elegant though. Truthfully, most of the problem relies on a fundamental property with xor that was very difficult for me to correctly apply.

If we treat each switch configuration as a node and draw edges, then we want to find a minimum length path from our initial switch state such that the xor of all the nodes on the path is equal to the current light state; this means that all lights are turned off. There's not enough memory or time to precalculate all queries from all states, but it is possible to precalculate them from the one state where all switches and lights are initially turned off (the bitmasks are zero).

Let $dp[i][mask]$ be a boolean that represents if, in exactly $i$ moves, we can get the lights to the state $mask$. It may seem nebulous as how to calculate it but for now we can simply assume that it's possible (I'll explain later). Then for each test case, we're given the light and switch states $L$ and $S$. An upper bound on the number of moves is $3N$, so fix the number of moves $i$. We can pretend that all the switches are initially turned off by taking advantage of the fact that xor is associative. In other words, take the xor of all bitmasks when simulating the process for $i$ moves without flipping the state of any switch (call this xor $X$). Then we check if $dp[i][L\oplus{X}]$ is true.

How to calculate the dp: we will separate all the xors again. If we are on some $dp[i][mask]$, then for each move from $1\dots{i}$, we change the state of some bit. If we look at each bit change individually, the first bit basically turns on a subsequence of length $i$, the second a subsequence of length $i-1$, etc. The xor of all these subsequences is $mask$. So to calculate $dp[i][mask]$, we just try adding a subsequence of length $i$ (denote $X$) at any of the $N$ positions, then check if $dp[i-1][X\oplus{mask}]$ is true. All this will achieve an $O(N^2*2^N+TN)$ runtime.

## 3. Moo Route
Sad that I missed that it was a dp. Once I saw that it was a dp from a solution then it became really clear to me.

Each $a_i$ value must be comprised of $a_i/2$ R's and $a_i/2$ L's, so divide each $a_i$ by $2$. Now let $dp[i]$ be the amount of ways to create a valid route with the minimum number of direction changes, given that we have considered all $a_j$ with $j\in[i,N]$.

We can treat the current route as a mountain range. To extend a mountain range from $dp[i+1]$ to $dp[i]$, our goal is to add $a_i$ upstrokes and $a_i$ downstrokes, each from $y=i$ to $y=i+1$, while still preserving the validity of the current route. First, we first have to add an upstroke on the very left and a downstroke on the very right. Then, excluding the two at the endpoints of the mountain range, we notice that there are $a_{i+1}-1$ different locations where the current route hits $y=i+1$. These are the only locations that we can add strokes from $i$ to $i+1$ at, i.e. extending the route to hit $y=i$. This is achieved by adding two strokes \\/ (a wedge) at this location.

We have two cases: $a_i<{a_{i+1}}$ and $a_i\ge{a_{i+1}}$. For the first case, we can't add a wedge to every location, so we can only add at most one wedge at each location in order to minimize the number of direction changes. There's no point in adding two to a single location because the first wedge we add at each location adds $0$ direction changes, but all future ones add $2$ extra. We have $a_{i+1}-1$ possible locations, and $a_i-1$ wedges to add (because we spent one on the upstroke and downstroke at the ends of the mountain range). Therefore, $dp[i]=dp[i+1]*{{a_{i+1}-1}\choose{a_i-1}}$.

For the second case, we add at least one wedge to every location, and at least zero wedges on the endpoints of the mountain range. To get around this, we can count the endpoints of the mountain range as locations as well (so add $2$ to the current number of locations), and add a corresponding downstroke to the upstroke at the beginning and an upstroke to the downstroke at the end, such that both of them become wedges. This is equivalent to increasing the number of wedges to add by $1$, because we add two extra strokes. Then, we can say that we want to add at least one wedge to every single location. By stars and bars, we have $a_i+1$ total wedges to add and $a_{i+1}+1$ locations, and thus $dp[i]=dp[i+1]*{a_i\choose{a_{i+1}}}$.

Aside from the binomial coefficient precalculation which takes $O((\max{a_i})log(MOD))$, the base calculation takes $O(N)$.