# USACO Gold 2023 December

## 1 - Flight Routes

Solving in $O(N^3)$ is easy: just use range dp. There are $O(N^2)$ states and each transition takes $O(N)$.
 - When solving for a range $[i,j]$ assume a direct flight from $i$ to $k$ for all $k$ in $[i,j]$ and if it exists add the answer for the range $[k,j]$ to the current answer for the range $[i,j]$. At the end, if the parity of $[i,j]$ is different from the given input, then there must exist an edge between $i$ and $j$.

Here I will cover my $O(N^2)$ solution (because I did not think $O(N^3)$ would pass with $N<=750$). In this solution we'll explicitly construct all paths (and a graph).

First iterate in descending order from $N$ to $1$. This ensures that for a given $i$ we already know all the flights between pairs of nodes with indexes greater than $i$, which is basically all relevant flights.

Then for this starting point $i$, we iterate over all its possible flights $j$ ($j>i$) in ascending order. Clearly, if $i_{i+1}$ is $0$ in the input, then there doesn't exist an edge from $i$ to $i+1$, and vice versa. If there does exist the edge, then we'll create the edge in the graph, and iterate over all edges beginning at $i+1$ to update the parities of its successors. After this we repeat for node $i+2$. If the current parity of node $i+2$ is not equal to the input, there then exists an edge between $i$ and $i+2$. So we'll draw an edge, and then update its successors.


## 2 - Minimum Longest Trip

I solved this a while ago (with immense help from the solution) but I will just briefly cover it right now.

Perhaps we should isolate the problem to finding just the length of the longest trip. Topologically sort the graph, and use dp to store the longest path from every node. The base cases are the nodes with outdegree $0$, or with indegree $0$ if we reverse all the edges (so we start from those nodes as well, provided we use Kahn's algorithm). 

Now, to find the lexicographically minimum path. We won't maintain a constantly updated queue for Kahn's algorithm, but instead do it in iterations to ensure we have all the answers for the parents before moving on to the children. If in some iteration multiple nodes point to the same child, then the child will inherit from the parent with the longest path. If there are ties, then the child inherits from the parent with the lowest label pointing to this node. If there are ties again, then the child inherits from the parent with the lexicographically minimum longest trip (a dp relationship). Basically, at the end of each iteration we'll rank all nodes in the current pool by the first label on their path and then by rank of their parent.