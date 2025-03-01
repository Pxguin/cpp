# COCI 2016 Round 2

## 5. Zamjene
Maintain the components with DSU. Let the set of positions in this component be $S$, the multiset of all $q_i$ for $i\in{S}$ be $Q$, and the multiset of all $p_i$ for $i\in{S}$ be $P$.

This component is good (sortable) if $P=Q$. To easily check this, hash the sets by assigning a random number to each number in the array, then taking the sum of all those numbers. We can update the hashes as we update the components.

For type 4 queries, we first want to find pairs of <b>components</b> $i$ and $j$ such that $P_i+P_j=Q_i+Q_j$. Let's define a hash $R=P-Q$; then we just have to check $R_i=-R_j$. Any pairs of indices, one from component $i$, and another from component $j$, will satisfy the requirements for a pair counted in a type 4 query. So for components $i$ and $j$, that's $sz_i\cdot{sz_j}$ pairs where $sz_i$ is the size of component $i$. 

To answer the query we just have to find the amount of all these pairs, so it's pretty easily done by storing a map on $R$. We can use this map to query, for some $R$, the sum of all $sz_j$ such that $R_j=R$. That way, we can, for some component $i$, find the sum of all $sz_j$ such that $R_j=-R_i$. And then, we just add $sz_i$ times the sum of all $sz_j$ to the number of pairs.

For type 3 queries, we just count the number of components such that $P\ne{Q}$, i.e. $R\ne{0}$. This is updated similarly to everything else.

The problem is solved in $O(NlogN+Q\alpha(N))$, when using unordered maps.