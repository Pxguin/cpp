# USACO Silver 2021 January

## 1. Dance Mooves

This problem is quite similar, but more complex than Swapity Swapity Swap (but the gold version is even better). We can simulate the $K$ swaps one time and track where each cow ends up, then draw a directed edge from $a$ to $b$ if a cow starting at position $a$ ended up at position $b$ (note that the cow will go through intermediate positions before reaching $b$, so let's store all the intermediary ones in a set denoted $S[i]$ - the size of all $S[i]$ combined won't exceed $2K$). So we end up with a functional graph. Note that this graph will only consist of cycles - a position can't map to more than one position after the $K$ swaps, nor can two positions map to the same position after $K$ swaps. 

Without loss of generality we can reduce the graph to a single cycle. Because the swaps continue indefinitely, then this cow will reach all positions in its cycle (and as a result also reach all $S[i]$ of all nodes in the cycle). Following this, we can note that every cow in the cycle will have the same answer. So take the union of all $S[i]$ to find the amount of distinct positions, then the size of the resulting set is the answer for all nodes in the cycle (you can do this with a multiset in $O(KlogK)$ or a frequency array in $O(K)$). It takes $O(N+K)$.

## 2. No Time to Paint

For each query we leave some range unpainted, so the answer for that query is the min strokes to paint everything to the left side of the range plus the min for the right side. We'll store these values with prefix and suffix sums. 

Here's a greedy strategy for calculating the sums:
Define the fence is $F[i]$. Also set $paint[c]$ to true or false depending on if we are currently painting a range of color $c$. 

If $F[i]$ is lighter than $F[i-1]$, then stop all ongoing ranges with color darker than $F[i]$ (set $paint[c]$ to false). Otherwise, if we are currently painting a range with color $F[i]$ then ignore this; otherwise, start a new range of color $F[i]$. The time complexity is $O(N*\Sigma +Q)$ where $\Sigma$ is the size of the alphabet.

## 3. Spaced Out

The optimal solution is that every column should alternate between an empty space and cow to get the maximum cows placed down, or that every row should alternate (but I'll only consider columns for now). These are the only restrictions, so we can calculate the maximum beauty for each column independently. A column can either start with an empty space or a cow, so take the maximum of both situations and then sum the answer up for all columns. Alternatively, you can do the alternating pattern on each row, so repeat the algorithm for all rows. It will take $O(N^2)$.