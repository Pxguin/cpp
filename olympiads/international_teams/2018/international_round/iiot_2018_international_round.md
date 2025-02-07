# IIOT 2017/2018 International Round

## Flowers
Solve independently for each letter so memory can be reused (doing it simultaneously will MLE). This is basically a version of [CSES - Tree Distances II](https://cses.fi/problemset/task/1133). We will try to pool all flowers of the desired type to each node and take the node yielding the minimum cost. To do this, calculate two values $in[i]$ and $out[i]$ storing the minimum cost to get all flowers in the subtree of $i$ to $i$, and to get all flowers outside the subtree of $i$ to $i$, respectively. The answer is the minimum value of $in[i]+out[i]$.

To calculate these arrays we need a third array $num[i]$ which stores the number of flowers of the desired type in subtree $i$. This is the easiest to calculate, and is done with dp. Now, $in[i]=\sum(in[x_j]+num[x_j]\cdot{d_j})$ for children $x_j$ of $i$, where child $x_j$ is connected to node $i$ by a road of length $d_j$. $out[x_j]=out[i]+(in[i]-(in[x_j]+num[x_j]\cdot{d_j}))+(num[i]-num[x_j])\cdot{d_j}$; i.e, the total cost of moving all flowers not in the subtree of $x_j$ to node $i$, plus the cost of moving all those flowers from node $i$ to $x_j$.

This solution runs in $O(\Sigma{N})$.