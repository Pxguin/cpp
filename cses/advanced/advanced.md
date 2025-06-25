## Meet in the Middle
Use meet in the middle to find all subsets, then combine them with lower bound.

## Houses and Schools
Solve the problem: divide the houses into $K$ disjoint ranges, and select a house in each range to build the school. The children in a house go to the school that is in the same range as the house. The goal is to minimize the total walking distance of children.

Each range can be subdivided into two more ranges: from the left endpoint of the range to the school, and from the school to the right endpoint of the range.

Let's say the left range is $[l,m]$. Then the total walking distance of all children in this range is $m(\sum_{i=l}^m{c_i})-\sum_{i=l}^m(ic_i)$.

The right range is $[m,r]$. The total walking distance is $\sum_{i=m}^r{ic_i}-m(\sum_{i=m}^r{c_i})$.

All summations can be simplified with prefix sums. Then just run a dp with two arrays $dp_l[i][k]$, storing the minimum cost for $k$ ranges with the last ending at $i$ (and we have only completed the left half of the last range) and $dp_r[i][k]$ (having completed the right half of the last range). The dp can be done with CHT to solve the problem in $O(NK)$.

## New Roads Queries
Make a graph with the weights of the edges as the time each road is created.
Then the answer for each query is the minimum maximum edge on a path from node A to node B, which can be done with a Min Spanning Tree + LCA.

Alternative Solution:
Use a persistent DSU and for each query binary search on the minimum time that nodes A and B are in the same component.