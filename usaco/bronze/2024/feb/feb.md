# USACO Bronze 2024 February

## 2. Milk Exchange
If a cow gives away milk, but doesn't receive milk, then we lose $1$ milk/minute until this cow's bucket is empty. Once this cow's bucket is empty, then the cow that it gives milk to won't receive milk from this cow anymore, so if no other cow passes to it, then we'll continue losing $1$ milk/minute until that cow's bucket is empty, and so on. 

We can subdivide the ring of cows down into components all consisting of a string of $R$'s followed by a string of $L$'s. Assume that it's something like $RRRRLLL$. Then cow $4$ and cow $5$, the adjacent $R$ and $L$, will always pass to each other so they'll never lose milk. For cows $1\dots{3}$, we consistently lose milk at a rate of $1$ milk/minute (following from the first paragraph) until all those buckets are empty, which will be at minute $(a_1+a_2+a_3)$. Therefore, the total amount lost by minute $M$ is $min(M,(a_1+a_2+a_3))$.The same logic goes for cows $6\dots{7}$. If we sum up all the milk lost by minute $M$, which can be done by a linear sweep through the array, then just use complementary counting to find the remaining quantity of milk. This achieves a runtime of $O(N)$.

As a sidenote, it may help to rotate the circle until the last cow is an $L$ cow, so we can avoid having to iterate through the array in a circular fashion later.

## 3. Maximizing Productivity
We can precalculate all queries by finding the maximum amount of farms that we can visit for each time that Bessie wakes up. Then if the maximum for $S$ is $\ge{V}$, then the query works.

For some given $S$, the maximum amount of farms that work are the number of farms that close strictly after $S+t_i$. So for each farm find the maximum $S$ ($M_i=c_i-t_i-1$) such that this farm is still visitable, and it holds that you can visit this farm for all $S\le{M_i}$. This means that the answer for a given $S$ is the number of $M_i\ge{S}$ which can be done with binary search or prefix sums. At best the runtime is $O(N+Q)$.