# USACO Gold 2022 December

## 2. Mountains

The problem really boils down to one observation, that is that if we fix the first mountain of every pair, then the slopes to the second mountain of those pairs must be in increasing order. Importantly, the converse also holds true in that every increasing slope produces a valid pair. So our solution is to fix $i$, then a mountain works if its slope to $i$ is greater than the maximum slope so far. A set $seq[i]$ will store this sequence (sorting by slope), and the size of the set is how many pairs work starting with mountain $i$. Now when we update some mountain $t$, we rewrite $seq[t]$. Then, for all $i<t$, we try adding $slope[i][t]$ (self-explanatory) to $seq[i]$. If there exists some element in the set with a greater slope but a lower index than $t$, then $t$ doesn't belong in the set and we remove it. Otherwise, we remove all elements with a lower slope but a higher index. $O(N^2logN+QNlogN)$.

The editorial has a nice way of comparing fractions: instead of checking ${a\over{c}} \le {b\over{d}}$ it compares $ad \le bc$.

I originally missed the converse and went into a rabbit hole of fixing the first and second mountains ($a$ and $b$), the finding the minimum slope from $b$ to all mountains in the range $(a,b)$. Then we find the minimum $y$ such that a valid pair exists and check if $a_y >= y$. But updates didn't work well; I pushed some theory about the maximum number of removals across all queries (which I believe is under $N^2$, but idk really)

## 3. Strongest Friendship Group

### Solution 1

For simplicity, assume the graph is a single connected component. 
Then we should constantly remove the minimum degree vertex and recalculate the answer for each removal.

Assume the minimum degree vertex for some component is $T$, and the size of the component is $S$.
If you remove a vertex with degree $> T$, then the minimum for the resulting components is either $T$ or $T-1$.
The new sizes are also $\le S$, so this will always be worse than the current answer.
So removing any vertex with degree $= T$ will work. However, recalculating the size of each component during removals is quite slow.
To solve this, we can simulate all removals, then reverse them so that we process additions to the graph, which can be done quickly with DSU.

Complexity: $O(M\alpha(N))$

### Solution 2 (covered in official editorial):
I thought this solution was nice and much simpler. It also followed one of my initial (failed) thought processes before the above solution.

We can fix one of two variables, either the minimum friends or the size of the component.
If we fix the minimum friends, we need to find the maximum component size in the resulting graph.
If we fix the component size, we need to find the minimum friends over all components of that size.
Clearly, we want to iterate over all possible values of the first variable.

By constantly removing vertices with degree $< T$ (the min friends) and then calculating the largest component it takes $O(M^2)$.
We can iterate over $T$ in ascending order and preserve vertice removals between values of $T$; thus the graph will be empty by $\sqrt{M}$ iterations.
So the runtime is $O(M\sqrt{M})$.