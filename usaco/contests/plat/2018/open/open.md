# USACO Plat 2018 US Open

## 3. Disruption
Each edge $M$ (connecting nodes $a$ and $b$) is a valid candidate to reconnect the farm for any edge that we remove that is on the simple path between $a$ and $b$.
 - This is because when removing an edge $(u,v)$ (assume $u$ is deeper than $v$), we can only reconnect the farm by connecting a node in the subtree of $u$ with a node outside the subtree of $u$. We can show that all such edges lie on the simple path between $a$ and $b$.

So turn each of the $M$ roads into that simple path, and let the value of that path be the length of the road. We can take all those paths and use lazy propagation (in a binary lifting sort of way) to find the minimum value of a path passing through each edge. It runs in $O((N+M)logN)$.