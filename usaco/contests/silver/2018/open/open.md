# USACO Silver 2018 US Open

## 1. Out of Sorts
Let $x_i$ be the amount of times "moo" is printed until this element reaches its desired position, $s_i$. The answer is the maximum $x_i$. 

The algorithm given is a stable sort, so we can rewrite the array as a permutation, and the algorithm will work the same. For example, $2,2,1$ becomes $2,3,1$. Now, if $i\ge{s_i}$, then $x_i=i-s_i$ because it moves $1$ unit to the left every iteration. If $i<s_i$, then element $i$ gets sorted to its correct position all in one iteration, because bubble sort continuously moves only the largest element to the end. This element is holding up some $j$ with $j>i$ and $j\ge{s_j}$, so $j$ will never reach their correct location until $i$ is sorted. Which means, this $x_i$ must be greater than that $x_j$, so we don't really care about $i$. Basically return the maximum $x_i$, so $O(N)$.

## 2. Lemonade Line
To get the minimum number of cows, the cows with the highest $w_i$ should join first. So sort $w_i$ by high to low and find the first cow that won't join. Every other cow after that has a lower $w_i$, so we can stop here because they will also not join. It is $O(NlogN)$.

## 3. Multiplayer Moo
It's pretty interesting but I'm not the biggest fan of it, because the finer details are hard to observe even though the main bulk of the algorithm is quite easy to figure out.

The one cow answer is done by a flood-fill. Each component $i$ has a color $c_i$ and a size $s_i$. The maximum area covered by two cows will be a connected component of two colors. There are only up to $4N^2$ possible two color pairs because each component is adjacent to at most $4$ other unique colors. So draw an edge between components $i$ and $j$ if they are adjacent, and then run dfs for each two color pair to find the maximum size of a connected component containing only those two colors. Nodes may be reused, but edges won't. So the runtime is $O(N^2)$.