# USACO Silver 2015 Feb

## 1. Censoring (Silver)
Read the bronze solution first. Instead of brute-forcing, in $O(|T|)$, whether the last characters are equal to $T$, we can just compare the hashes of the last $|T|$ characters in $O(1)$.

## 2. Cow Hopscotch (Silver)
$dp[i][j]$ equals the number of ways to get to cell $i,j$. $dp[i][j]={\sum_{a=0}^{i-1} {\sum_{b=0}^{j-1} dp[a][b]}}$ assuming the color of $a,b$ is different than the color of $i,j$ (add all cells with a different color that can jump to this cell). So $O(R^2C^2)$.

## 3. Superbull
Draw an edge between every pair of nodes where the weight of the edge is the xor of the two nodes (i.e. the points scored in the game between these nodes). The answer comes from the weight of a maximum spanning tree. Any valid set of games will always form a tree, so this works.