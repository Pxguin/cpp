# CSES Range Queries

## Dynamic Range Sum Queries
Segment tree, but store the sum for each interval. $O(NlogN)$.

## Dynamic Range Minimum Queries
Segment tree, but with each range storing the min of the range. $O(NlogN)$.

## Range Xor Queries
We can use a segment tree on the XOR, or use prefix sums with xor (xor of $[a,b] = ps[1,b] \oplus ps[1,a-1]$). $O(NlogN)$.

## Range Update Queries
Use a segment tree on the difference array of the given array, so we still have point updates and range sums. In other words, convert the array $a[i]$ to a new array $diff[i]$ such that $diff[i]=a[i]-a[i-1]$ for all $i$. Then when updating a range $[a,b]$ by $x$, add $x$ to $diff[a]$ and subtract $x$ from $diff[b+1]$. When querying a single element at index $i$ take the prefix sum of the difference array up to $i$, which can be done w/ the segtree. So $O(NlogN)$.

## Distinct Values Queries
We can use complementary counting to find the number of distinct values. For a value at position $j$, let's find the last occurence of $a[j]$ (denote it $i$). Then, if any query contains the range $[i,j]$, then it contains the value $a[j]$ twice. Generalizing this, the amount of ranges a query contains equals the amount of duplicates in the range. But in order to do this quickly we have to answer queries offline (I won't go into specifics because it's pretty simple, you could see USACO Silver 2022 Jan Cow Frisbee as an example). In total it takes $O(QlogN)$.

## Increasing Array Queries
Let $T$ denote the final values of our subsequence after performing the operations, and $S$ as the initial. Through some casework, we say that for each element $S_i$ in the $[a,b]$ range, $T_i$ is equal to the largest value (in the range $[a,b]$) that is to the left of $S_i$. 

Instead of trying to find the largest value for each element, we can shift our focus to finding the range when each element $i$ is the largest value. This range is bounded by the nearest larger value on the right of $i$ (call it $j$), meaning that all elements in the range $[i,j)$ will have a final $T$ value of $S_i$.

We're looking for nearest larger values on the right side, so we will process all queries offline by iterating backwards over $a_i$, and use suffix sums to find the answer. We know all the $T_i$, so our goal is to find ${\sum^{b}_{i=a}} T_i-S_i$. After simplification to ${\sum^{b}_{i=a}} T_i - {\sum^{b}_{i=a}} S_i$ we can see that the both halves can be managed by computing independent suffix sums. For clarification on the summation of $T_i$, remember that certain elements are the $T_i$ value for a range of numbers $[c,d)$. So maintain suffix sums on each range (i.e., $T_i*(d-c)$) and use lower/upper bound to find where each $b_i$ lands in those ranges. Final complexity is $O(Qlog(Q+N))$.