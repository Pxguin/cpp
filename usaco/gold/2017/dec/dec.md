# USACO Gold 2017 December

## 1. A Pie for a Pie

We could represent this as a graph with a directed edge between two pies if the second pie can be given directly after the first. Then we would do a multisource BFS from all pies with tastiness value $0$ (Bessie's pies that Elsie considers to have tastiness $0$, and vice versa). The issue is that we may run into $N^2$ edges, which won't run with $N\le{10^5}$ (at least I don't think it runs). But consider the nature of BFS: it only will update the distance of nodes if they are currently set to infinity. So with this, we just need to maintain separate multisets for Bessie's and Elsie's pies. Each of them stores the current pool of nodes with distance infinity, and we remove nodes as needed. It takes $O(NlogN)$.