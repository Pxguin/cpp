# USACO Gold 2021 Feb

## 1. Redistributing Gifts
If we calculate the amount of reassignments for every subset of cows then queries are easy to deal with. We simply take the answer for the subset of all $H$ positions, and for all $G$ positions, and permute them. But onto the actual problem: following from the silver problem, draw a directed edge from $i$ to $j$ if $i$ can receive $j$'s gift after reassignment. Note that there will be a self-loop from $i$ to $i$ because the cow can keep its gift. After this, the number of valid reassignments for subset $i$ are the amount of simple cycles using nodes within subset $i$. 

My first intuition was to do something that ended up as 11D on codeforces (in fact it's just a harder version of that problem) where you find the number of Hamiltonian cycles for every subset and then try to combine the answers to get the number of simple cycles for each subset. But combining the answers turns out to be very difficult because we need to deal with overcounting issues. It's easier to just calculate the answer during the initial dp. So building on the solution to 11D, at any point we can obviously continue the cycle, or end the cycle (if possible) and start a new one. Additionally, when we end the current cycle, we should start the new cycle on a less significant bit than the one of the current bitmask to avoid overcounting. The final solution runs in $O(N^2*2^N)$.

## 3. Moo Network
An MST algorithm runs in $O(N^2)$. But for each cow, we only care about creating an edge between it and the closest cow to the left and to the right (in terms of x-coordinate) on each y-level.

For example, assume that there's four points $(0,0),(5,1),(6,1),(-1,1)$. For the point $(0,0)$, we only care about the edges $(0,0)\longleftrightarrow(5,1)$ and $(0,0)\longleftrightarrow(-1,1)$ because they are are the closest to $(0,0)$ on the line $y=1$. Basically, we don't need to consider the point $(6,1)$.

The resulting number of edges is a small factor of $N$ so we can just run the MST algorithm after this. In total, the time complexity is $O(NYlog(NY))$; $Y=\max(y_i)$.