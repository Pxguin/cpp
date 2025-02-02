# Google Code Jam 2022 Round A

## D. Checksum
If we have exactly $N-1$ known values in a row, then we can derive the final value by using the checksum. There is no other way that we can definitively deduce the values of the matrix.

Knowing this, we will recover the grid to a point where we are able to figure out the remaining unknown values of the matrix. If we treat rows and columns as nodes, and for each of those remaining unknowns, connect its row and column with an edge, then the graph formed is a tree. The intuition is that we can't form cycles because it's impossible to derive values that are in a cycle (visualizing it in the rows and columns is easier).

We can first assume that we assume that we recover all values. The cost of this is the sum of all $B$. Then our goal is to find the maximum spanning forest of the graph. All edges selected for this correspond to the cells that we won't recover, so obviously we want to maximize the sum of $B_{i,j}$ for those cells. Time complexity after sorting (if using Kruskal's) is $O(N^2logN^2)$ per test case. I assume that the time limit must have been really high/fast judge, because even with using fread/fwrite it still ran in 6 seconds on my computer (36 seconds without). I also had to check test cases by hand so the solution might be wrong.