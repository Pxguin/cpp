# USACO Bronze 2020 Jan

## 2. Photoshoot
The $O(N^2)$ solution: fix the value of $a_1$, which can be in the range $[1,N]$. Now we use the values of $b_i$ to recursively figure out all values of $a$ ($a_i=b_{i-1}-a_{i-1}$), and if the final array is a permutation, then it works. We use the minimum value of $a_1$ that works.

The $O(N)$ solution: let the candidate array if we have fixed $a_1=i$ be $b_i$. When incrementing $a_1$ to $i+1$, then $b_{i+1}$ can be derived from $b_i$ instead of being recalculated entirely. All values at odd indices decrease by $1$, and all values at even indices increase by $1$.

We know that $\min_{1\le{j}\le{N}}(b_{i,j})=1$. So first find $b_1$. Now we can calculate the minimum time until some odd index in $b_1$ reaches value $1$, and the maximum time until some even index reaches value $1$. Let these candidates be $d_1$ and $d_2$. So there are only two candidates to consider for $a_1$, being $b_{1,1}+d_1$ and $b_{1,1}+d_2$ respectively, and we can test both of them for a total time complexity of $O(N)$.

## 3. Race
Bessie's trip can always be rewritten such that she accelerates every second until she hits some top speed $X$, at which she'll only decrease or maintain her speed in the remaining seconds. Call the speed at which she finishes the race the end speed.

For each top speed $X$, we can calculate the minimum end speed such $S_X$ that she can still finish the race. This tells us that Bessie can finish the race with a top speed of $X$ and an end speed in the range $[S_X,X]$. This is done with two pointers (because as $X$ increases, $S$ increases) or binary search.

Finally, to answer queries. We should find the maximum top speed $X$ such that its minimum end speed $S_X$ is less than or equal to the speed $x$ given in the query. Only then can we finish the race.

We can reduce the race to the following: Bessie constantly increases her speed up to $X$, then maintains a speed of $X$ for as many seconds as possible such that she can still finish with a speed of $x$; then, she constantly decreases her speed down to $x$. It may be the case that after decreasing down to $x$, she still doesn't finish the race, so the remaining distance $K$ will be travelled at whatever time she is at $K$ speed.

The increasing and decreasing is fixed, so the number of seconds it takes to do that is $X+(X-x)$. The distance travelled in these seconds is also easily calculated as sums of arithmetic sequences. Letting the remaining distance be $K$, we'll then add on $\lceil{K\over{X}}\rceil$ to the answer, for a time complexity of $O(Nlog(logK))$.