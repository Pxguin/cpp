# USACO Bronze 2019 Dec

## 1. Cow Gymnastics
Let $rank[c][s]$ be the rank of cow $c$ in exercise $s$. Any two cows can then be easily compared in $O(1)$ time per exercise by comparing their ranks. Brute force over all cows and exercises for an $O(N^2K)$ time complexity.