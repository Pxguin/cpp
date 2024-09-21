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