# USACO Silver 2025 US Open

## 2. Compatible Pairs
Assume $A\ne{B}$

Draw a bidirectional edge between two nodes if their labels sum to $A$ or $B$.

Each node is incident to at most two edges; the sum of degrees in a connected component of size $S$ is $2S$. So each connected component is either:
 1) a tree
 2) a tree plus one edge (that creates a simple cycle)
 3) a tree with $1$ or $2$ self loops

### Case 1
There is an easy greedy assignment from the leaves up.

### Case 2
This case can never exist (a simple cycle can't exist).

For any simple path, the sum of endpoints of the edges on the path must alternate between $A$ and $B$. So any simple cycle has an even number of edges.

Suppose a cycle of length $k$ exists (proof by contradiction). Let's find any edge in the cycle whose endpoints sum to $A$. Number the vertices $a_1,a_2,\dots,a_k$ in the order of the cycle starting from the larger endpoint (number the larger endpoint $a_1$ and the smaller endpoint $a_2$, then continue numbering vertices along the cycle in this order).

$n[a_1]>n[a_2]$, so $n[a_1]>A/2$ and $n[a_2]<A/2$. Since $n[a_3]=B-n[a_2]$, then $n[a_3]>n[a_1]$. Thus $n[a_4]=A-n[a_3]<n[a_2]$, $n[a_5]>n[a_3]$, etc.

The values at odd positions form an increasing sequence, and the values at even positions form a decreasing sequence. $k$ is even, so $n[a_k]<n[a_2]$. Thus, $n[a_k]+n[a_1]\ne{B}$, contradicting the fact that a cycle exists.

### Case 3
Suppose two self loops exist. If so, they will never be in the same component.

Proof by contradiction: let's find these two vertices with self loops $x$ and $y$ ($x=A/2$ and $y=B/2$), and list out the vertices on the simple path between $x$ and $y$ in the same way as the cycle from Case 2.

$n[a_1]=A/2$, $n[a_2]=B-n[a_1]>n[a_1]$, $n[a_3]<n[a_1]$, etc.

The values at odd positions form a decreasing sequence, and the values at even positions form an increasing sequence. The largest value at an odd position is $n[a_1]=A/2<B/2$, and the largest at an even position is $n[a_2]=B-n[a_1]>B/2$. Therefore, no vertex has value equal to $B/2$, violating the assumption that a simple path exists between $x$ and $y$.

### Conclusion
So each connected component is either a tree, or a tree with one self loop. The latter case is a new case, but we can just treat it as the first by rooting the tree at the vertex with the self loop and running the greedy algorithm while ignoring the self loop. At the end, pair up as many remaining cows at the root as possible via the self loop.

$O(N)$

## Comments
Problem 2: My code ends up basically doing the same thing as the official editorial, but getting there is different. I think that if my way was the official solution it should 100% be way too hard for silver because it requires a fair amount of intuition that is not silver level (at least I got it down to $O(N)$ rather than $O(NlogN)$ though). I think that the official editorial's solution is still harder than silver level though (which I guess is expected because it's US Open).