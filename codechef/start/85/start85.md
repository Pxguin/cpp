# CodeChef Starters 85

## 3. TripTastic
Binary search on the minimum distance. For some distance $x$ and the mentor position $(i,j)$, the set of all cells within a Chebyshev distance of $x$ away from the mentor is contained by the square defined by the top left and bottom right corners $(i-x,j-x)$ and $(i+x,j+x)$. We can query the sum of all spots in these cells with prefix sums, and it remains to check if the amount of available spots is $>K$ or not. If so, then there's enough spots to fit all students, and so the distance of $x$ works.

Time complexity is $O(NMlog\max(N,M))$.