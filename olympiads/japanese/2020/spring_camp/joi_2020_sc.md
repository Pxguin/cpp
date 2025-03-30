# JOI 2020 SC Day 2

## 2. Making Friends on Joitter is Fun
Hard (I think at least 2400 on CF, most likely 2500)

Call an edge "saturated" if it's bidirectional; i.e. both users follow each other.

After the social event, all components of saturated edges become cliques. We can first calculate this preliminary answer with DSU. If there exists an edge from some node $a$ to a node in component $b$, then after the social event there will exist edges from $a$ to all nodes in $b$. So generalizing, we can merge two components $a$ and $b$ if there exists an edge from some node in $a$ to some node in $b$, and vice versa.

If we store the merged adjacency lists of each component, then we can repeatedly merge any two components connected by a bidirectional edge. So store for each component $i$ the size of the set of nodes $S_i$ that follow some person in $i$, and the size $sz_i$ of $i$; then the answer is the sum of all $|S_i|\cdot{sz_i}-sz_i$.

When merging two components, we go small to large. We maintain a queue of components to be merged. Store the compressed graph (each node is a component; merged adjacency lists). When merging $a$ and $b$, we combine their adjacency lists and update the answer, and also check if any new components can be merged. If so, add them to the queue.

So, it runs in $O(MlogN)$ with unordered sets to store adjacency lists.