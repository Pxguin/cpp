# Amman Collegiate Programming Contest 2016

## D. Rectangles
See <b>CEOI 2020 - Fancy Fence</b> and <b>CSES - Maximum Building I</b>. This problem is basically a combination of the two, so if you can solve those then this should be easy. The only difference is that there are multiple colors to deal with in this problem, so you have to process each separate block of a color.

## K. Topological Sort
It is a similar idea to [CF 920E - Connected Components?](https://codeforces.com/contest/920/problem/E). In fact, the code is virtually identical. We compute the topological sort with a dfs and make sure only to process nodes 1) that are currently unvisited 2) that are greater than the current node 3) such that the corresponding edge between it and the current node is not in the removed edges list.