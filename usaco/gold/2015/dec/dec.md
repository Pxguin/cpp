## USACO Gold 2015 Dec

## 2. Fruit Feast

DP to find the max value without drinking water. Then, for every currently achievable value, divide by 2 (drinking water).
After this, do DP again from these new values and take the max of the two DPs.

## 3. Bessie's Dream
This is Dijkstra/BFS, except we need to store extra information such as if Bessie currently smells, and (in the case of BFS) which direction she's moving in. Then the transitions are simply casework by following the properties of the adjacent tiles. It runs in $O(NM)$.