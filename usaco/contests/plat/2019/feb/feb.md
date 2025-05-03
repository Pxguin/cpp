# USACO Platinum 2019 February

## 1. Cow Dating
The probability for an interval $[l,r]$ is $\sum_{i=l}^{r}({{p_i}\over{1-p_i}}\cdot\prod_{i=l}^{r}(1-p_i))=\sum_{i=l}^{r}{p_i\over{1-p_1}}\cdot\prod_{i=l}^{r}(1-p_i)$. Let this value be $f(l,r)$.

Suppose we have fixed $l$ and $r$. It turns out that a two pointer approach is possible; $[l,r+1]$ is better than (or equal to) $[l,r]$ if $f(l,r+1)\ge{f(l,r)}$, which, after simplification, gives $\sum_{i=l}^r{{p_i}\over{1-p_i}}\le{1}$. The monotonicity of this property lets use two pointers, which runs in $O(N)$.

## 2. Mooriokart
We are given $K$ disjoint trees and need to select one path from each tree such that the sum of the paths is $\ge Y-KX$. After calculating the lengths of all paths, a simple knapsack dp runs in $O(NY^2)$ if we group paths by length and also compress all paths $\ge Y-KX$ into one dp state. At the end, multiply by $(K-1)!$ because we are arranging the order of the tracks in a circle. Also, multiply by $2^{K-1}$ because each path in every tree can be traversed both ways. It should be $2^K$, but we must divide by $2$ to avoid over-counting because tracks can be traversed in both directions.

Improving the algorithm relies on the fact that there aren't that many distinct path lengths. It is most unoptimal to split into ${N\over{\sqrt{Y}}}$ trees of size $\sqrt{Y}$, so each tree has at most $Y$ distinct path lengths. Thus, the runtime is $O({N\over{\sqrt{Y}}}Y^2)$, or $O(NY\sqrt{Y})$ which proves to be an accurate representation of the time complexity.