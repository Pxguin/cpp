# USACO Gold 2019 Feb

## 2. Dishwashing
I may or may not have tunnel visioned on a binary search. But the official editorial is practically just an improved version of the binary search, which I was trying to figure out.

There is a simple greedy strategy to check the first $M$ plates: in order to get the dishes in the correct order, then at any point in time, each stack must have indices in decreasing order from the bottom, and all indices in a stack must be strictly greater than the stacks before it. So there is exactly one possibility of which stack to add plate $i$. After adding the plate, we pop dishes off the front stack if they belong next in the sorted pile. If at the end we have successfully sorted all plates, then it's possible. $O(NlogN)$.

The improved $O(N)$ solution is the same as the above, but don't pop dishes off the front stack unless necessary. It's necessary if at some point we can't place the current dish on top of any stack, so then we'll have to remove all stacks before, and part of the stack that it belongs to. If while popping those stacks we find that the answer stack is not properly sorted, then we'll terminate. Using this, we can determine the maximum prefix able to be sorted. I have the code as well.