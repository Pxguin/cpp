# CCC: 2020 Senior

# 3. Searching for Strings

In order to deal with any permutation of $N$ we'll just store the frequency of each character and test if they match up with a substring. To do this efficiently use a sliding window on $H$, so you can test all susbtrings in $O(HA)$ time where $A$ is the alphabet size. However, we only want to find the number of distinct permutations, so we can just maintain a set of string hashes, using the polynomial hash to differentiate different permutations (I used a map, idk why). It is important to note that $M=10^9+7$ causes collisions so I followed with the USACO guide example and chose $2^{61}-1$, although this does require $128$ bit integer multiplication. It takes $O((|N|+|H|)A)$ time.