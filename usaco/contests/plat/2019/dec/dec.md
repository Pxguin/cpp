# USACO Plat 2019 Dec

## 1. Greedy Pie Eaters
This problem can be solved with range dp. The motivation behind this is because for a new cow to eat a pie, it must not be contained inside any existing range so far. So let $dp[l][r]$ be the maximum sum of weights for a sequence of cows, such that their union is inside of the range $[l,r]$. The union does not have to equal $[l,r]$ but rather can be a subset of the range, which is very important because 1) it simplifies dp transitions a lot, and 2) the union is not always a continuous range. We have two main transitions: the first is that we can combine two subranges into the range $[l,r]$. So $dp[l][r]=\max(dp[l][r],dp[l][k]+dp[k+1][r])$ for $l\le{k}<r$.

It's helpful to think of the second transition by starting with a subcase. If there exists such a cow $i$ such that $l\le{l_i}\le{r_i}\le{r}$, and $l_i=l$, then we can extend the range $[l+1,r]$ by one unit. So, $dp[l][r]=\max(dp[l][r],dp[l+1][r]+w_i)$. The same logic applies if $r_i=r$ instead. 

It should be clear that instead of extending the range to the left and right, we can also fill up some gap in the middle of two ranges. Only a single cow will fill up the gap (it's impossible to have more than one because the previous transitions should have accounted for that configuration), and we can therefore assume the gap is of length $1$ because only one cow is filling it anyways. We get the transition $dp[l][r]=\max(dp[l][r],dp[i][k-1]+mx[l][r][k]+dp[k+1][r])$ where $mx[l][r][k]$ specifies the maximum weight of a cow $i$ satisfying $l\le{l_i}\le{k}\le{r_i}\le{r}$. This is the equivalent of filling up a gap at index $k$, between the ranges $[i,k-1]$ and $[k+1,r]$.

The array $mx$ can be calculated with dp in $O(N^3)$. Similarly, the dp array is calculated in $O(N^3)$, so overall the time complexity is $O(N^3)$. Note that in my solution, the subcase for the second transition is kept as its own transition because I had already written the code and didn't feel like deleting it.

## 2. Bessie's Snow Cow
Flatten the tree with preorder traversal. If all colors in queries were distinct, then it would be a simple range update/range query which can be done with Fenwick trees. But extending to distinct colors isn't that hard: when we need to update the subtree of $i$ with color $c$, then we just delete all preexisting queries updating a node in the subtree of $i$ with color $c$.

So the time complexity is $O(N+QlogN)$.