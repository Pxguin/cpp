# USACO Gold 2020 US Open

## 2. Favorite Colors

Truthfully the solution to this problem isn't that difficult. What I found super hard was getting to the solution because I must have went through three different algorithms before finding the correct one.

### Solution

By default, we should assume every cow has a distinct favorite color, and then relax contradictions in the graph as necessary. At first we'll have an issue if two cows admire the same cow. Then they must have the same favorite color, so we can merge them with DSU. Then the goal is to constantly merge two cows as long as they belong to different components and each admire cows in the same component. Implementing this is as follows: if there are two edges with the same $A$ value, then combine the components of their $B$ values. Do this by maintaining for every component the list of edges with an $A$ value inside the component, then merge all the $B$ values. To store the list of edges merge small-to-large in the unite function, which achieves a time complexity of $O(MlogN)$.

### Solution Process

Initial solution: I split up the solution into two parts, uniting components by a less precise rule, then increasing the precision to unite a second time. It only worked if components were united in a specific order, so I gave up on it.

Second solution: I combined into one uniting, and noted that if there is an edge with an $A$ value inside a component then all other edges with $A$ values inside the group can be united into it. It was implemented messily and with error but led to my final correct solution. It also failed on a side case.

Third (final solution): I realized that if we have the edges for each group then we can just unite all of them into one group, avoiding the issue with the side case in my previous solution. I ran into a really tricky segmentation fault side case that took me 1-2 hours to debug though (the side case led into a second even harder side case). If you're curious it's in lines 48-52. $adj[cur]$ can be equivalent to $adj[y]$ in the unite function leading to a pop_back being called when the vector is empty. I implemented this with error:

unite(cand,adj[cur].back()); <br>
if (adj[cur].size()>1) {adj[cur].pop_back();}

The issue is that I may call pop_back during the unite function and then call it a second time after, which effectively skips elements. I solved it by not calling pop_back if the vector size changed in the unite function.