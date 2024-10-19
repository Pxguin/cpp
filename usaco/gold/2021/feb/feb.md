# USACO Gold 2021 Feb

## 1. Redistributing Gifts
If we calculate the amount of reassignments for every subset of cows then queries are easy to deal with. We simply take the answer for the subset of all $H$ positions, and for all $G$ positions, and permute them. But onto the actual problem: following from the silver problem, draw a directed edge from $i$ to $j$ if $i$ can receive $j$'s gift after reassignment. Note that there will be a self-loop from $i$ to $i$ because the cow can keep its gift. After this, the number of valid reassignments for subset $i$ are the amount of simple cycles using nodes within subset $i$. 

My first intuition was to do something that ended up as 11D on codeforces (in fact it's just a harder version of that problem) where you find the number of Hamiltonian cycles for every subset and then try to combine the answers to get the number of simple cycles for each subset. But combining the answers turns out to be very difficult because we need to deal with overcounting issues. It's easier to just calculate the answer during the initial dp. So building on the solution to 11D, at any point we can obviously continue the cycle, or end the cycle (if possible) and start a new one. When we end the cycle we must start the new one on a less significant bit than the one of the current bitmask. The final solution runs in $O(N^2*2^N)$.