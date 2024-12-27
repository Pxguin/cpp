# USACO Gold 2019 US Open

## 3. Balancing Inversions
We only want to swap a $0$ and $1$ because that's the only swap with an actual effect. The swaps between elements $N$ and $N+1$ (center swaps) are the most problematic, so we'll ignore those for now. Otherwise, let the number of inversions in the first half be $I_1$ and the number in the second half be $I_2$. If we swap a $1$ to the left, then we gain an inversion, and otherwise, we lose an inversion. So we can say that given $I_1$ and $I_2$, the minimum number of swaps (without center swaps) needed to balance out the inversions is equal to $|I_1-I_2|$, as we can always decrease the number of inversions in the larger number until it reaches the smaller one.

Center swaps are one-way: across all center swaps we'll only swap $1$'s from the right half to the left half, or only from the left to the right half. Given these two cases, we can either make any number of center swaps from the right to left half, or vice versa. So we can just try all possibilities of center swaps, update $I_1$ and $I_2$, and update our answer. 

WLOG assume that we are swapping from the right half to the left half. We need a $1$ in position $N+1$, so move the earliest $1$ in the right half to this position (via a sequence of continuous swaps) and update the inversions accordingly. We need to get a $0$ in position $N$ in the left half, so move the latest $0$ to that position). After this, swap $N$ and $N+1$ and update the inversions (with some casework). Let the total number of moves needed to get to this point be $M$. If the inversions in the left and right half are $I_1$ and $I_2$ after these $M$ moves, then compare the answer with $M+|I_1-I_2|$ and take the minimum. After this, try the next possible center swap, update $M$, $I_1$, $I_2$, and the answer, etc. until no center swaps are possible anymore from the right half to the left half.

Then we have to try swaps from the left to the right. I reverse the array, so $01$ pairs are now inversions instead of $10$ pairs. Some more casework gives us the new ways to recalculate the number of inversions in each half after a center swap.

Time complexity: $O(N)$.