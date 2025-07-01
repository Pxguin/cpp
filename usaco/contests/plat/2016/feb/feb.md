# USACO Platinum 2016 February

## 1. Load Balancing
Binary search on $M$ and go through all possible vertical lines. For each vertical line, calculate the range of horizontal lines for each quadrant such that the there appears no more than $M$ cows in each quadrant. Then a vertical line is valid if the four ranges intersect. 

To simplify this, I coordinate compress the cows so I can easily group them by x-coordinate. Then I sweep over all vertical lines, and maintain a 2p for the horizontal line to find the range for a set quadrant. Repeat for all four quadrants to get the ranges. $O(NlogN)$.

## 2. Fenced In
(solve the Gold version before).

(or at least solve it but not implement it, like me lmao)

We still want to find an MST but need to do it faster. Now if we rename the # of horizontal fences as $H$ and vertical as $V$, then there are $H$ copies of the distance between each pair of adjacent vertical fences, and vice versa. This means we can store all edges in $N+M$ memory, and similarly iterate over them in that time complexity. First sort to prepare for Kruskal's.

If we are on some edge, then we'll remove try to remove all copies of that edge (either $H$ copies or $V$ copies) in the corresponding row or column. The number of copies is pretty easy to find; $V+1-$# of columns removed (if you're trying to remove a row) or $H+1-$# of rows removed (if you're removing a column). Also note that for the MST we must remove at least one row and one column so take that into consideration. $O((N+M)log(N+M))$, and my first plat problem!

## 3. Circular Barn
Gold version but with CHT $O(N^2K)$.