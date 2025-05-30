## 1. Fine Dining

It makes sense we want to use Dijkstra to initially find the shortest paths from all nodes to node N.

Then, a solution would be to consider for all nodes i if there is an optimal path with a haybale in it.
We can consider the set of nodes K (all nodes that have haybales), and then check:
 - For every i, considering all nodes j in set K, if dist(j,n)+dist(i,j)-dist(i,n) <= yumminess[j].
Unfortunately, the time limit isn't fast enough for computing all pairs dist(i,j), nor going through every node j for every node i.

However, we can observe that dist(i,j) can be recursively calculated from some node j using Dijkstra.
Rewriting the equation as dist(j,n)-yumminess[j]+dist(i,j) <= dist(i,n),
we can run a multisource Dijkstra with distances initialized to dist(j,n)-yumminess[j] for all nodes in set K,
and thus calculate the minimum dist(j,n)-yumminess[j]+dist(i,j) for all i.

It remains to simply compare this distance to dist(i,n) to get our answer.

## 2. Cowpatibility
By the inclusion-exclusion principle, go through each subset of flavors of size $1$, and add the amount of pairs of cows both containing this subset in their favorites. Then subtract the amount of pairs of cows both containing subsets of size $2$, add for $3$, etc. There are a lot of possible flavor subsets, but only $2^5-1*N$ that we have to consider under the constraints of this problem. So, the solution runs in $O(2^CN)$ where $C$ is the amount of each cow's favorite flavors.

## 3. Teamwork

Do knapsack dp for a runtime of O(NK).
Basically dp[i] stores the maximum for the cows 1...i (assuming all of them are in teams), then try to build teams size 1...k for each i. 