# USACO Gold 2019 Dec

## 2. Milk Visits
We can divide up each query by LCA. Let $f(c,i)$ be the number of nodes of type $c$ on the path from $i$ to the root. We can then check if the amount of nodes of type $c_i$ on the path from $a_i$ to $b_i$ is positive — if so, then the answer to query $i$ is yes. The amount of nodes in question is equal to $f(c_i,a_i)+f(c_i,b_i)-2\cdot{f(c_i,lca(a_i,b_i))}$, plus $1$ if $T_{lca(a_i,b_i)}=c_i$ and $0$ otherwise.

We can process queries offline. Get an Euler tour of the tree and then partition the nodes by milk type into separate arrays. We can now express $f(c,x)$ (for any $x$) as a prefix sum of the array corresponding to $c$, so we can get this for all queries with two pointers.

So, the time complexity is $O((N+M)logN)$.