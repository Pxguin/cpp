# USACO Plat 2020 Dec

## 1. Sleeping Cows
Suppose that at least one cow isn't matched. Fix that cow $c$. Then all cows $i$ with weight $<s_c$ must be matched, and all barns $j$ with $t_j\ge{s_c}$ must be matched as well.

So for each cow $c$, do an $O(N^2)$ dp. First concatenate together cows and barns, and sort all of them. Then $dp_c[i][j]$ is the amount of matchings given we have considered up to index $i$ and have $j$ cows left to match. If index $i$ is a cow, then we can choose either to match it with a barn later (so transition to $dp_c[i+1][j+1]$), or not match it at all. If $i$ is a barn, then we can choose to match it with any of the $j$ cows (transition to $dp_c[i+1][j-1]$), or not match it at all.

We also must satisfy the constraints: all cows smaller than $c$ and all barns that can house $c$ must be matched.

To speed up to $O(N^2)$ total, combine all dps into one. The dp table for each cow $c$ can be split into two parts: all indices before $c$ and all indices after $c$. For the first half, it is necessary to match all cows. For the second half, it is necessary to match all barns. So in a single $O(N^2)$ pass we can compute all the prefix values (all values of $dp_c[c][j]$ for all $c$ and $j$). Now we can simply calculate the answer in a second $O(N^2)$ pass, since the only constraint now is that we need to use all future barns.