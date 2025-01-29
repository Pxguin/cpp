# USACO Gold 2021 Feb

## 1. Redistributing Gifts
If we calculate the amount of reassignments for every subset of cows then queries are easy to deal with. We simply take the answer for the subset of all $H$ positions, and for all $G$ positions, and permute them. But onto the actual problem: following from the silver problem, draw a directed edge from $i$ to $j$ if $i$ can receive $j$'s gift after reassignment. Note that there will be a self-loop from $i$ to $i$ because the cow can keep its gift. After this, the number of valid reassignments for subset $i$ are the amount of simple cycles using nodes within subset $i$. 

My first intuition was to do something that ended up as 11D on codeforces (in fact it's just a harder version of that problem) where you find the number of Hamiltonian cycles for every subset and then try to combine the answers to get the number of simple cycles for each subset. But combining the answers turns out to be very difficult because we need to deal with overcounting issues. It's easier to just calculate the answer during the initial dp. So building on the solution to 11D, at any point we can obviously continue the cycle, or end the cycle (if possible) and start a new one. Additionally, when we end the current cycle, we should start the new cycle on a less significant bit than the one of the current bitmask to avoid overcounting. The final solution runs in $O(N^2*2^N)$.

## 2. Cow Camp
Define $E_x$ as the maximum expected value for submitting at most $x$ times. Transition from $E_{x-1}$ to $E_x$ not by adding one submission to the back, but instead adding one to the front. Specifically, assume that the score for the first submission is $s$. If $s<E_{x-1}$, then we'll follow the optimal strategy for $E_{x-1}$ for the remaining $x-1$ submissions, to get an final expected score of $E_{x-1}$. If $s\ge{E_{x-1}}$, then we stop submitting and get an expected score of $s$. The probability of getting a score of $x$ (denoted $p_x$) is equal to ${T\choose{x}}\cdot{1\over{2^T}}$, which can all be precomputed with a recurrence relationship. $p_x=p_{x-1}\cdot{(T-x-1)}/{x}$; just modify the factorials in the binomial coefficient.

The recurrence relationship is $E_x=(\sum_{i=\lceil{E_{x-1}}\rceil}^{T}i(p_i))+(\sum_{i=0}^{\lceil{E_{x-1}}\rceil-1}E_{x-1}(p_i))$. The first term, which I will refer to as $a_x$, is if we get a score higher than the expected value. The second term is the other case and will be referred to as $b_x$.

$a_x$ covers some suffix of the array, and $b_x$ covers some prefix. We can easily compute $E_x$ if we find the splitting point $j$ between these two ranges. We then use prefix sums and follow the above formula. This solution would run in $O(KlogT)$, which is sufficient for subtask 2.

$E_x$ is at least as large as $E_{x-1}$, so the expected value is non-decreasing. This means that $j$ is also a non-decreasing pointer (that will move at most $T$ times). $j=\lfloor{E_x}\rfloor$, so we can compute the range $(l,r)$ in which $j$ is constant $(\lfloor{E_l}\rfloor<j<\lfloor{E_r}\rfloor)$. We can binary search on the right endpoint of the range (the left endpoint is derived from the right endpoint of the range for $j-1$) and skip over $E_r-E_l-1$ submissions all at once by composing the recurrence relationship for $E_x$ on itself $E_r-E_l-1$ times, which can be simplified to a geometric sum.
 - A composition of $L$ times is just $a(a+b(a+b(\dots(a+b(E_{x-1})))))$ where $a+b$ appears a total of $L$ times. This simplifies to $(a\cdot\sum_{i=0}^{L-1}b^i)+b^L(E_{x-1})=(a\cdot{{1-b^L}\over{1-b}})+b^L(E_{x-1})$.

The time complexity is $O(Tlog^2K)$ because we call the pow function (which I think runs in logarithmic time) $O(TlogK)$ times.

## 3. Moo Network
An MST algorithm runs in $O(N^2)$. But for each cow, we only care about creating an edge between it and the closest cow to the left and to the right (in terms of x-coordinate) on each y-level.

For example, assume that there's four points $(0,0),(5,1),(6,1),(-1,1)$. For the point $(0,0)$, we only care about the edges $(0,0)\longleftrightarrow(5,1)$ and $(0,0)\longleftrightarrow(-1,1)$ because they are are the closest to $(0,0)$ on the line $y=1$. Basically, we don't need to consider the point $(6,1)$.

The resulting number of edges is a small factor of $N$ so we can just run the MST algorithm after this. In total, the time complexity is $O(NYlog(NY))$; $Y=\max(y_i)$.