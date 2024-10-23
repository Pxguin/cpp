# USACO Silver 2015 Feb

## 1. Censoring
Read the bronze solution first. Instead of brute-forcing, in $O(|T|)$, whether the last characters are equal to $T$, we can just compare the hashes of the last $|T|$ characters in $O(1)$.

## 3. Superbull
Draw an edge between every pair of nodes where the weight of the edge is the xor of the two nodes (i.e. the points scored in the game between these nodes). The answer comes from the weight of a maximum spanning tree. Any valid set of games will always form a tree, so this works.