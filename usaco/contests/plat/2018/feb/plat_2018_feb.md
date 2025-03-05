# USACO Plat 2018 Feb

## 2. New Barns
The graph is a forest. We can root each tree at the earliest node in that tree, thus ensuring that build queries are the equivalent of adding leaves to the tree.

WLOG assume only one tree. The farthest node from any node must be one endpoint of the diameter — consider the method of finding the diameter via two DFS's (alternatively, proof by contradiction). If we can maintain the diameter at any point, then we can easily answer distance queries.

For build queries, we can say that whenever adding a leaf to the tree, the new diameter should contain one or both endpoints of the old diameter (proof by contradiction again). If it contains both endpoints, then the old diameter remains unchanged. Otherwise, the new endpoint is the barn just built, so we can find the new diameter now.

Therefore, the solution runs in $O(QlogQ)$.