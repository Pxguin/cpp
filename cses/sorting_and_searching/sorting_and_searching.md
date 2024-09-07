# CSES Sorting and Searching

## Nested Ranges Check

Well my IOI Empodia solution works on the official test data but fails on the codeforces IOI archive extra tests, so I'm busy debugging that. This nested ranges check algorithm is part of my solution and I seem to have done it correctly because it works on the CSES tests. 

Sort all ranges by increasing $l$, then by decreasing $r$ in the case that $l$ is the same. 
To check whether a range is contained inside another one store the maximum $r$ value so far (call it $R$) and if this range has $l \le R$ and $r \le R$ then it is contained.
To check whether a range contains another range store a stack of ranges. When you add a new range, pop elements from the stack while those ranges contain this one. The elements left in the stack at the end don't contain any ranges inside them.

## Subarray Sums II

For every prefix sum $A$ find the # of prefix sums to the right of this with value $A+x$, which can be done by maintaining a map of all PS and their frequency, and then subtracting $A$ before calculating its value (for all $A$).