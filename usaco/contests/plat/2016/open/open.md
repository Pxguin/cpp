# USACO Plat 2016 US Open

## 1. 262144
An upper bound for the answer is $M=log_2(N)+40$. Building from the gold solution, there is only one possibility for what each range in the array can collapse to. But more generally, if the left endpoint of the range is $i$ and we want the range to collapse to $j$, then there exists exactly one possibility for what the right endpoint of the range can be. So let $dp[i][j]$ be the right endpoint for a range with a left endpoint at $l$ and collapsing to $j$. There are most $NM$ ranges, and doing transitions is pretty easy dp. So in total, the time complexity is $O(NM)$.

My code stores $left[i][j$ (equivalent to $dp[i][j]$) and $right[i][j]$ (fixing the right endpoint) which is for transition purposes, although not necessary. The editorial also has an elegant $O(N)$ solution.