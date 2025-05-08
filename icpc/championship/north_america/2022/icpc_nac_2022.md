# ICPC North America Championship 2022

## GCD Harmony
Some bounds on the final values of each node. $\forall{i}$, it's always ok to have $a_i\le{100}$. Otherwise, the following must be satisfied:
 - $a_i<2N$; otherwise changing each node's value to $2$ is a less costly construction.
 - $a_i$ is not a prime greater than $100$.
 - Consequently, $a_i$ is not a multiple of a prime greater than $100$.
 - $a_i$ is square free (all prime factors are distinct).

That leaves $1435$ integers to consider. Run a tree dp; $dp[i][j]$ is the min cost to make the subtree of $i$ gcd harmonic given $a_i$ has been changed to $j$.

Two numbers don't have a gcd of $1$ if they have at least one prime factor in common. So the dp can be sped up fast simply by looping through all prime factors of each $j$. The time complexity is $O(N^2\pi(v))$ but the extra constraints from above speed it up significantly.