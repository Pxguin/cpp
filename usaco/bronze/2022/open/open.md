# USACO Bronze 2022 US Open

## 3. Alchemy
There is at most one recipe for each metal so if we are trying to make copies of a certain metal, then we can only use the recipe provided (if it exists). So we'll start from metal $N$, and if a recipe exists for metal $N$, then we'll create as much of it as possible with the materials we currently have. Now, if we want to form more of metal $N$, then we need to form more of the metals required to create metal $N$. So for each of those metals, we want to check if we have a copy of it. If we do, then set it aside for making a copy of metal $N$ later; if we don't, then we need to craft it from its recipe, so check those metals. If at any point we have all the metals required to make metal $N$ then make a copy of it. It will run in $O(N^2(maxa_i))$.

It's easier to explain it as a directed graph: set $N$ as the root, and draw edges from each metal to the metals required to craft it. We'll store a list of metals containing the current decomposition of metal $N$, referred to as $D$. At first, $D = {N}$. Then we'll repeat the following process:
 - For each element in $D$, check if you have a copy. If you do then ignore it because you'll use it to create metal $N$.
 - Otherwise, remove this element from $D$ and add all its children to $D$ (if the recipe exists. If it doesn't then you stop here, because you have the final answer already).
 - If in any iteration you make no changes to $D$, then you'll use one copy of all metals in $D$ to make a new copy of metal $N$, so subtract $1$ from each $a_i$ for all $i$ in $D$.