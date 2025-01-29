# USACO Silver 2017 US Open

## 2. Bovine Genomics

Brute force over all sets of three positions. A set of positions is sufficient to explain spottiness, if none of the plain and spotty cows share the exact same values for these $3$ positoins (otherwise FJ can't tell these cows apart). It is possible to maintain a hashmap of sorts but it is also fine to hash the genome by converting it to base-10 like I did - as a note, the editorial converts to base-4 which is more convenient. So, it runs in $O(NM^3)$.