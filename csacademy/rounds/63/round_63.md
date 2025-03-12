# CSA Round 63

## 5. Root LCA Queries
If $C$ is not on the path from $A$ to $B$, then the answer is zero.

Root the tree at node $1$. Given $i$ is an ancestor of $j$, let $f(i,j)$ return the child of $i$ that is also an ancestor of $j$. Let $sz_i$ be the subtree size of $i$.

If $C$ is an ancestor of $A$, then all nodes in the subtree of $f(C,A)$ don't work. Same goes for $B$.

If $C\ne{lca(A,B)}$, then only nodes in the subtree of $C$ can be possible values for $D$. Otherwise, all $N$ nodes can be possible values for $D$.

So let the initial answer for this query be $N$ if $C=lca(A,B)$, and $sz_C$ otherwise. If $C=lca(C,A)$, then we subtract $sz_{f_(C,A)}$ from the answer. If $C=lca(C,B)$, then subtract $sz_{f_(C,B)}$ from the answer.

The LCA queries result in an $O((N+Q)logN)$ runtime.