# USACO Silver 2020 Dec

## 2. Rectangular Pasture
(solved 7 months ago, but forgot to add ig)

For a given subset, find the strictest rectangle that contains all cows. The left side of each rectangle is bounded by the cow with the smallest x-coordinate, and same for the right side. So iterate over all these $N\choose{2}$ pairs.

For a given pair of cows $i$ and $j$, the two cows define the minimum and maximum x-coordinate of any other cow that can belong to this subset. Which means, if you draw a rectangle from $i$ to $j$ (denote $I$) and then extend it in the y-axis infinitely (denote $B$), all candidates must be in this rectangle. Also, if you have two cows $a$ and $b$ both in $B$ and above $I$, and with $a_y>b_y$, then it's impossible to have the subset $\set{i,j,a}$; the only valid subset will be $\set{i,j,a,b}$. Therefore, if we denote the amount of cows in $B$ and below $I$ as $D$, and above $I$ as $U$, then there are exactly $(U+1)(D+1)$ possibilities for this set. Use coordinate compression and prefix sums to find $D$ and $U$. At the end, make sure to add $N$ cows, and also $1$ for the empty subset. The runtime is $O(N^2)$.