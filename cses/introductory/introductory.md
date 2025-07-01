# CSES Introductory Problems

## Missing Number
Sum hashing?

## Two Sets
If $N\equiv{1,2}\pmod{4}$ then $\sum_{i=1}^N{i}$ is odd and there is no solution.

For four consecutive numbers $x,x+1,x+2,x+3$, we can divide into two groups of equal sum $x,x+3$ and $x+1,x+2$.

If $N\equiv{0}\pmod{4}$ then split into groups of $4$ consecutive numbers and equate sums with the above construction.

If $N\equiv{3}\pmod{4}$ then remove the first three numbers, assign $1,2$ to one set and $3$ to the other, and now the remaining elements can be split into groups of $4$ by the same construction.

$O(N)$.

## Digit Queries
The first $9$ numbers each contribute $1$ digit; the next $90$ numbers contribute $2$ digits, then $900$ contributing $3$, and so on. So from $k$, subtract $9*1$ digits if possible (the amount of numbers with $1$ digit), then subtract $90*2$ if possible, and so on. When you can't subtract anymore, then you'll know two things: the length of the number that the $kth$ digit is in, and also how many digits remain. All the remaining digits must belong to length $k$ numbers so take divide by $k$, and now you can easily figure out the exact number that the $kth$ digit is in. From here, just take the position that corresponds to the $kth$ digit. The above method yields an $O(QlogK)$ algorithm.