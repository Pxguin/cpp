# JOI 2016 Spring Camp Competition 1

## 1. Matryoshka
Sort all dolls by $H$, and consider only their respective $R$ (I tried sorting by radius and it didn't work out, but it turns out that it's possible with pretty much the same idea as I used, take a look at the usaco guide solution). To answer a query, we just take the subsequence of dolls satisfying that query and find the longest non-decreasing subsequence.

Process all queries offline, which lets us fix $B_j\le{H_i}$. Now, the goal is to find the length of the longest non-increasing sequence, out of all remaining dolls satisfying $A_j\ge{R_i}$. 

To do this, let's take a look at the dp array that we're using to calculate the LIS. $dp_k$ denotes the maximum $R$ value that's at the end of a non-increasing subsequence of length $k$. This means that we can answer the query by binary searching for the first value $\ge A_j$ in the dp array. The position of that element tells us the length of the longest non-increasing subsequence comprising of values strictly $\ge{A_j}$, so the position of the element is also our answer for this query.

Time complexity: $O((N+Q)logN)$.