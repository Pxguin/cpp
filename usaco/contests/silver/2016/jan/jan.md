# USACO Silver 2016 Jan

## 3. Build Gates
Ok the alternative solution in the editorial using Euler's formula is so interesting. The boring solution is to flood fill to find the amount of fenced in regions (connected components), and the answer is the amount minus one because we can combine two regions together with a gate. Expand the grid in such a way so that fences, which would originally be line segments, are now cells as well. This is necessary so that we can run a proper flood fill.

Time complexity: $O(N^2)$.