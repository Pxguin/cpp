# COCI 2016 Round 2

## 5. Zamjene
Maintain the components with DSU. Let the set of positions in this component be $S$, the multiset of all $q_i$ for $i\in{S}$ be $Q$, and the multiset of all $p_i$ for $i\in{S}$ be $P$.

This component is good (sortable) if $P=Q$. To easily check this, hash the sets by assigning a random number to each number in the array, then taking the sum of all those numbers. We can update the hashes as we update the components.

For type 4 queries, we first want to find pairs of <b>components</b> $i$ and $j$ such that $P_i+P_j=Q_i+Q_j$. Let's define a hash $R=P-Q$; then we just have to check $R_i=-R_j$. Any pairs of indices, one from component $i$, and another from component $j$, will satisfy the requirements for a pair counted in a type 4 query. So for components $i$ and $j$, that's $sz_i\cdot{sz_j}$ pairs where $sz_i$ is the size of component $i$. 

To answer the query we just have to find the amount of all these pairs, so it's pretty easily done by storing a map on $R$. We can use this map to query, for some $R$, the sum of all $sz_j$ such that $R_j=R$. That way, we can, for some component $i$, find the sum of all $sz_j$ such that $R_j=-R_i$. And then, we just add $sz_i$ times the sum of all $sz_j$ to the number of pairs.

For type 3 queries, we just count the number of components such that $P\ne{Q}$, i.e. $R\ne{0}$. This is updated similarly to everything else.

The problem is solved in $O(NlogN+Q\alpha(N))$, when using unordered maps.

## 6. Burza
Daniel marks a node at each depth (starting from $1$), since Stjepan can only move the coin deeper from the root.

The maximum amount of moves before the game ends is not very large. In the worst case, all paths are equally good. Simultaneously, as to not use more nodes than necessary, each node only has two children. Thus one possible worst case may be a full binary tree, for which the game ends in $\lfloor{log_2N}\rfloor$ moves.

But we can do better. The amount of nodes required for each depth of the binary tree grows exponentially. It would be more efficient to connect $B$ chains to the root, each of length $N-1\over{B}$. The growth is linear, and the game ends in $\min(B,{N-1\over{B}})$ turns. The worst case of this is $B=\lfloor{\sqrt{N-1}}\rfloor=19$ when $N$ is maximized.

Let's restrict the tree to depth $\min(K,20)$ and ignore all leaves with lesser depth. When ordering the relevant leaves of this tree in preorder traversal, then marking a node takes care of a range of leaves. At the same time, $\min(K,20)$ implies bitmask dp. So $dp[mask]$ is the maximum prefix of leaves that can be covered given the depths of nodes marked so far make up the set $mask$.

Complexity: $O(2^{\sqrt{N}}N)$.