# USACO Gold 2012 Dec

## 2. First!
To start, for each string $i$, an $O(N)$ check can be done to see whether it can be lexicographically minimum in some permutation of the alphabet. First, if this string is a prefix of any other string, it's impossible. Otherwise, check it against all other strings $j$ to find the first position at which they differ. The character at that position, for string $i$, must appear earlier in the alphabet when compared to the character at that position for string $j$. All conditions are easily checked by building a graph with all 26 letters as nodes, and drawing a directed edge from the letter in string $i$ to the letter in string $j$. Then just see if a topological sort exists (i.e. acyclic). If it does, then string $i$ can be lexicographically minimum.

To speed up from $O(N^2)$ to $O(N)$, we can build a trie, as it easily lets us search up LCPs for strings (and thus lets us find the first position that two strings differ). Tries compress into letters, so the time complexity of checking for a string of length $i$ is only $O(26i)$. The total time complexity is only $O(\Sigma|S|+\Sigma^2N)$ where $|S|$ is the total length of all strings.

## 3. Running Away From the Barn
For each node $i$, find the farthest away ancestor $a_i$ such that the distance between $i$ and $a_i$ is $\le{L}$. Node $i$ is then reachable from any node on the simple path between $i$ and $a_i$. The answer for node $i$ is the amount of these paths that it intersects, which has already been seen in USACO Plat - Max Flow.

I missed a really easy binary jump solution to calculate $a_i$ (jump as far as possible from $i$ without exceeding $L$). Letting $d_i$ be the distance from $1$ to $i$, the distance between $i$ and $j=a_i$ is just $d_i-d_j$, so I instead find the farthest ancestor $j$ that satisfies the inequality $d_i-L\le{d_j}$. In other words, find the last $d_j\le{d_i-L}$, which, because $d_j$ are strictly decreasing, equates to one node before the first $d_j>d_i-L$. This is a classic problem on a segment tree (see CSES - Hotel Queries) that can easily be translated to binary jumping.

Time complexity, either way, is $O(NlogN)$. There exists a very simple $O(Nlog^2N)$ merging solution, but that's boring.