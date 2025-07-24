Not sure if this problem is in the correct folder, since Bubble cup seems to have deleted all info from previous years.

## Ray Needs Help
CSES - Graph Paths II with queries.

Repeating across each query takes $O(QN^3logK)$. The bottleneck comes from repeatedly squaring the transition matrix. If the powers of the matrix are memoized then it only takes $O(N^2logK)$ per query, so $O((N+Q)N^2logK)$.