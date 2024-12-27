# USACO Gold 2023 Feb

## 1. Equal Sum Subarrays
Fix $i$. For two subarrays to have equal sum, one of them must contain $i$, and one of them must not contain $i$. Otherwise, the sum of both subarrays change by the same amount. So we can check for each $i$ in $O(N^2logN^2)$ by grouping all ranges by the aforementioned property, sorting each group, and then using 2p to calculate the answer. This times out, but we can reduce the check for each $i$ to $O(N^2)$ if we sort all ranges by sum in the very beginning. So, the time complexity is $O(N^3)$.