# CSES Additional Problems

## Multiplication Table
Binary search on the median. To check, we make sure our value X is >= half of the values in the table.
Do to this, iterate over every row of the table and count the number of values that X is greater than or equal to with some basic math.
(If we are on row i, then X is greater than min(X/i, n) values)

## Advertisement
For every height, find the largest width of the advertisement assuming this is the minimum height in the ad (then take the maximum).
 - This implies finding the nearest smallest values on the right and left side of each value, which can be done with a stack.
The max width of the ad for this height will be right-left+1.

## Maximum Building I
This builds on the Advertisement problem. We can fix the bottom row and then calculate the maximum area like this similarly to the aforementioned problem.

## Xor Pyramid
I'll update when I prove the stuff used. For now we want to find how many times each element on the bottom row is xored, which are the binomial coefficients for $N-1$ (proof). We only care about the parity of the binomial coefficients and ${n\choose{k}} = {{n!}\over{k!(n-k)!}}$, so if the largest power of 2 in $n!$ (i.e. prime factorization) is $\le$ the sum of the powers in the denominator then the result is odd. To find the largest power of $2$ in $x!$ note $x! = x*(x-1)!$ so it is the sum of the answer of $(x-1)!$ and $x$ (use prefix sums). The alternate solution in my code relies on [this link](https://math.stackexchange.com/questions/11002/cn-p-even-or-odd) ok so update later when I actually understand all of that. $O(N)$ btw.