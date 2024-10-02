# USACO Bronze 2023 December

## 3. Farmer John Actually Farms
The $t_i$ must form a permutation from $0$ to $N-1$, so we are effectively given a specific order that plant heights must be in. If we sort by $t_i$, and for all adjacent pairs of plants find which days the second plant is taller than the first (represented by an inequality), then the union of these inequalities is when all plant heights are in the given order. If the union doesn't exist then it's impossible, and otherwise the minimum day it is satisfied is just the first point in the union.