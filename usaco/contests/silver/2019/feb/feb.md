# USACO Silver 2019 Feb

## 3. The Great Revegetation
Each component is independent, and the answer is the product of all answers for components. The answer/number of ways to color a component is either $0$ (no coloring exists) or $2$ (the coloring and its inverse exist). Checking if a coloring exists is a simple modification of a bipartite check. Greedily color nodes, as we can determine the single possibility for a node's color by looking at its neighbors, and stop if a contradiction is found. So, it runs in $O(N)$.