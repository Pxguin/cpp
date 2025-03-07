# ??? (Codeforces mirror #2073)

## G. Corrupted File
The indices we collapse in $B$ will form disjoint components. If the component consisted entirely of $1$'s, then the block collapses into a one. Otherwise, it collapses into a zero. So we're asked if we can split string $B$ into $|C|$ blocks, and upon collapsing them, transform $B$ into $C$.

i will rewrite this

I introduce a two pointer strategy:
 - First, split $B$ and $C$ into same-state continuous blocks. $11001$ becomes the blocks $11$, $00$, $1$.
 - We assign each bit in $C$ to a single block of size one in $B$. A zero in $C$ maps to a zero in $B$, and one to one. Obviously, not all bits are assigned. But we can validly fill in the rest of the array by extending the current ranges on the left/right sides. A zero bit can be extended however much because a block evaluates to zero if there's just one zero in it. A one bit can be extended up until it reaches a zero on the left/right, because a block evaluates to one if all bits are one.
 - So iterate over each block in $B$. If the block consists of $0$'s, then we assign these bits in $C$ to the next $|b|$ zero bits in $B$ (disjoint or not) where $|b|$ is the size of the block.
 - If the block consists of $1$'s, then it must be assigned to a continuous range of $|b|$ set bits in $B$. Otherwise, it'll be impossible to extend the ranges at the very end to cover the whole array $B$. So we find the earliest remaining range that works and assign it.

If assignment fails at any position, then return false. If all assignment works, return true. There's still a couple caveats where it fails (due to being unable to extend the ranges to cover the entire array) even if a valid assignment of single bits to single bits is found:
 - $C$ consists entirely of ones, but $B$ has at least one zero.
 - $C$ has a prefix of zeroes, but $B$ has a prefix of ones; alternatively, the prefix of ones in $B$ is smaller than the prefix of ones in $C$.
 - The second case, but on the suffixes of $B$ and $C$.