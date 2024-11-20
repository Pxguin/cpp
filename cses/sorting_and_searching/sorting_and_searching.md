# CSES Sorting and Searching

## Playlist
Solve with 2 pointers. Iterate over every left endpoint for a sequence, and for each one find the maximum right endpoint such that no two values repeat. First, the repetition can be maintained with a set. Second, the maximum right endpoint must monotonically increase for each left point; if you increase the left endpoint (and remove values from the sequence), then it's impossible that the maximum right endpoint will decrease with it. Because of the set, it takes $O(NlogN)$.

## Nested Ranges Check
Well my IOI Empodia solution works on the official test data but fails on the codeforces IOI archive extra tests, so I'm busy debugging that. This nested ranges check algorithm is part of my solution and I seem to have done it correctly because it works on the CSES tests. 
s
Sort all ranges by increasing $l$, then by decreasing $r$ in the case that $l$ is the same. 
To check whether a range is contained inside another one store the maximum $r$ value so far (call it $R$) and if this range has $l \le R$ and $r \le R$ then it is contained.
To check whether a range contains another range store a stack of ranges. When you add a new range, pop elements from the stack while those ranges contain this one. The elements left in the stack at the end don't contain any ranges inside them.

## Subarray Sums II
For every prefix sum $A$ find the # of prefix sums to the right of this with value $A+x$, which can be done by maintaining a map of all PS and their frequency, and then subtracting $A$ before calculating its value (for all $A$).

## Sliding Window Median
Store the sliding window and use an ordered set/order statistic tree to select the median (in $O(NlogN)$). Alternatively, binary search on a BIT (which takes $O(Nlog^2N))$. Or follow the solution to the next problem, which describes one in $O(NlogN)$.

## Sliding Window Cost
First pretend we're dealing with only a single window, and sort the array in this window. Assume that the element you are trying to get everything to is at index $X$. Then, fix the sum of nodes with index less than $X$ as $A$, and the sum of nodes with index greater than $X$ as $B$. The amount of nodes with index greater than $X$ is $|A|$ and similar logic for $B$. Now, the total cost equals to $(A-X|A|)+(X|B|-B)$. To simplify things, just have $A$ include index $X$ so all indices belong to either $A$ or $B$, and the formula should still hold.

Now, note that when you increase $X$, you save cost only if $|B|>|A|$. Same goes when you decrease $X$, but for $A$ instead. This general trend points to the fact that the optimal $X$ should be when $|A|=|B|$, or the index of the median. If there are two medians, then either will suffice (in fact, any real number between the two works).

It remains to be able to update $A$ and $B$ across all windows. This requires finding the median, and also all numbers with an index below it and all numbers with an index higher than it. So store two multisets each storing these numbers. When removing or inserting a number, just make sure to balance out the sizes of the multisets by transferring elements between them, such that they each represent everything to one side of the median (this means $|A|=|B|$ if $K$ is even; if $K$ is odd, we are including the median in $A$, so $|A|=|B|+1$). This should give all the information needed for the aforementioned formula. Calculation takes $O(NlogN)$.

## Maximum Subarray Sum II
Basically iterate over every window of length $b-a+1$. Assume the starting point of the window is at index $i$. Then you want to take the maximum $ps[j]-ps[i]$ for $i\le{j}\le(i+(b-a))$, and add it to $ps[i-a]$. In other words, you fix a block of length $a$ from indices $i-a+1$ to $i$, and then extend it anywhere from $0$ to $b-a$ units (obviously, you want to use the extension with the maximum sum). This is simplified to finding the maximum $ps[j]$, then subtracting $ps[i]$ and adding $ps[i-a]$. Taking the maximum $ps[j]$ over every window can be done with a sliding window + multiset, therefore in $O(NlogN)$.