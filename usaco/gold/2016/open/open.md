# USACO Gold 2016 US Open

## 1. Splitting the Field

We need to build two disjoint rectangles, which means there must be a vertical or horizontal line separating them. So we can try splitting a horizontal line between every adjacent pair of cows (same for vertical). I'll cover the horizontal line case - first sort the cows by x position, then for every possible split calculate the minimum area to enclose both cows on the left and right side of the line, which can be done by calculating prefix and suffix minimum/maximum x/y. It will take $O(NlogN)$.

## 2. Closing the Farm

I actually did this problem 4 months ago, but I guess I forgot to add it. Instead of closing farms we'll add farms in reverse order instead and test connectivity with DSU. When we add a farm we'll only add the subset of its edges that connect to currently unclosed farm. All in all the time complexity is $O(V+E\alpha(N))$. 

## 3. 248

For any given range, it can be reduced to a definitive single number or it can't be reduced. We'll test for all ranges whether they can be reduced, and if they can, what is the single number left in it. The answer is the maximum across all ranges. This will use DP, where $dp[i][j]$ contains the number for the range $i...j$, or $0$ if it doesn't exist. For each range iterate over all $k$ such that $i<k<j$, then the range $i...j$ is a combination of the ranges $i...k$ and $(k+1)...j$. In other words, if those two ranges can be reduced, and to the same number, then $dp[i][j]$ equals that number $+1$. To do this we have to iterate over all ranges in increasing size, and it achieves a runtime of $O(N^3)$.