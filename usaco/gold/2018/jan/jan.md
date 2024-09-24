# USACO Gold 2018 Jan

## 2 - Cow at Large
First, we root the tree at $K$. If $K$ is an exit barn then the answer is $1$.
Otherwise, observe the following: For a given node $i$, if some farmer can reach the node before Bessie, then the farmer 'controls' node $i$'s subtree - in other words, that Bessie won't be able to reach any barn in the subtree of node $i$.

Therefore, we should compute for every node the minimum distance for a farmer to reach it (i.e. dist to a leaf), and for Bessie to reach it (i.e. dist to $K$). These both can be done with BFS or DFS. After this we just do another DFS from node $K$, and if a farmer can reach a node before Bessie, then we add one to the answer and move on (because all nodes in the subtree are controlled); otherwise we DFS into its subtree.

This would also imply that when computing the min dist to a leaf from some node $i$, that we only have to consider leaves inside the subtree of $i$, because if a leaf outside the subtree of $i$ is closer to node $i$ then it should rather control the parent of node $i$.

## 3. Stamp Painting
My dp was pretty rigorously constructed. I would check out the official solution.

Define $dp[i]$ as the amount of ways to stamp the cells $1\dots{i}$. Our base case is $dp[K]=M$ ($dp[i]=0$ for $i<K$). Then we have two options: first, we can extend the range $[1,i-1]$ by $1$ cell of any color to get the range $[1,i]$, so add $dp[i-1]*M$ (you can extend by one cell if you paint this stroke before the strokes constituting $[1,i]$). Second, we can add a stroke of any color from $i-K$ to $K$, thus add $(M^{i-K}-dp[i-K])*(M-1)$. So $dp[i] = dp[i-1]*M + (M^{i-K}-dp[i-K])*(M-1)$. The runtime is $O(N)$ if we precalculate exponents.

Here are explanations for the second dp transition:
<details close>
<summary>Why M^(i-K)?</summary>
There are M^(i-K) possibilities for the first i-K-1 squares. It doesn't matter what's after them because by painting from i-K to K we're going to cover those anyways. 
</details>
<details close>
<summary>Why subtract dp[i-K]?</summary>
We already counted dp[i-K] ways for the first i-K-1 cells so subtract them from the total (this is simplifying it a bit - they are overcounted because we already consider them from repeated use of the first dp transition).
</details>
<details close>
<summary>Why multiply by M-1?</summary>
There are M total colors. But if the last stroke is the same color as the second-to-last stroke then we are overcounting again, because this is equivalent to having a stroke of length greater than K, which we already counted with the first dp transition mentioned earlier. So multiply by M-1 instead.
</details>