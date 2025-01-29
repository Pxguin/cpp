# USACO Gold 2023 US Open

## 1. Custodial Cleanup
First, get all keys possible. This is done through a BFS process — we can visit all nodes that we currently have the keys too. When we pick up a new key, we have to do some backtracking to figure out which new nodes are visitable.

There will be nodes $i$ that we can't visit. In this case, we can't get or place keys in those stalls, so the only way to reassign all keys is if $s_i=f_i$ to begin with. For the second part, I'll assume that these defunct nodes have been removed from the graph for simplicity.

The second part is to check if we can place all keys in their correct stalls. For a key of given color $C$, after placing down the last key of color $C$, then we can't traverse through any more stalls with color $C$ to get back to node $1$. In other words, letting $X$ be the color of the stall that the last key of color $C$ was placed in, there should exist a path from stall $1$ to that stall such that no stall of color $C$ is on the path (excluding endpoints).

We can simulate the process in reverse; we start from node $1$ and can only visit stalls of color $C$ after traversing some stall satisfying $f_i=C$ (thus ensuring that it's the last stall we place a key of color $C$ in, so there's a simple path back to node $1$ not going through any stalls of color $C$).

Time complexity is $O(N+M)$.

## 2. Pareidolia
Let $dp[i][j]$ be a pair that stores the maximum number of copies of bessie we can make, and the minimum cost for that maximum number, given that we have considered up to the $ith$ character, and have found the first $j$ characters of our next copy of bessie. Our answer is $dp[N][0]$.

We have three transitions: either extend the current copy of bessie if possible, so $dp[i][j]\rightarrow{dp[i+1][j+1]}$, stop extending the current copy of bessie, so $dp[i][j]\rightarrow{dp[i+1][0]}$, or delete the character at this position, so $dp[i][j]+del[i]\rightarrow{dp[i+1][j]}$. This has a runtime of $O(N|S|)$, $S$ being the string we're looking for ("bessie" in this case).

## 3. Tree Merging
I would probably ignore my solution; it's elegant in terms of the idea but implementation is not ok. Official solution is much simpler and easier to implement.

We can employ a dfs strategy, starting from the root of the tree. We look through all children of the current node, and will merge them if possible. We can see that if a child $a$ doesn't exist in the final tree, then it must be merged. We can find which sibling $b$ it must be merged into by looking at the subtree of $a$. For all nodes in the subtree of $a$ that appear in the final tree, $b$ must be their ancestor. A dfs will work to find the corresponding node $b$.

This is already sufficient for subtask $2$. The amount of leaves are the same, so for each valid node $a$ we'll always be able to find the corresponding node $b$ that it must be merged into. Finding $b$ takes $O(N)$ so the time complexity so far is $O(N^2)$.

Past subtask $2$, we have to deal with the case where no node in the subtree of $a$ appears in the final tree. First, we can compress the subtree of $a$ into a line by continuously merging nodes. Then we observe that for none of the nodes in this line to be present in the final tree, there must exist a path in the final tree (starting at a sibling of $a$) such that when merging the line and that path, we can get rid of the line altogether. In other words, each node on the path must be greater than the node at the same depth on the line.

It takes $O(N)$ to find a path for each line, but once we find a path, then we already know what we're merging each node on the line with (which is the node at the same depth in the path). So we can skip calculating for those nodes in the future. The time complexity therefore balances out to $O(N^2)$.