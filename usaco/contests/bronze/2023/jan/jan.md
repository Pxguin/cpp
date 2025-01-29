# USACO Bronze 2023 Jan

## 1. Leaders
Each cow's range only contains cows after itself so if a cow is a leader because her list contains all cows of her breed, then the only possible candidates are the first Guernsey and first Holstein. For the Guernsey leader, check to see how many Holsteins have lists containing this cow (by brute force or difference arrays on each range), and vice versa. $O(N)$.

## 2. Air Cownditioning 2
Go through each possible bitmask for AC units, i.e. brute force all possible combinations of AC units that we can turn on. For each combination, check to see if each cell is cooled sufficiently. If this is the case, then this combination of AC units works. Set the answer to the minimum cost of all combinations that work. This takes $O(2^M(DM)) where $D=100$, the length of the given range of units.