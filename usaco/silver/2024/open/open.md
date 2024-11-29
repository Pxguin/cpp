# USACO Silver 2024 US Open

## 1. Bessie's Interview
We can first just simulate the process. If two farmers finish at the same time, we'll arbitrarily pick one. Let the farmer that picks Bessie to be farmer $B$, finishing at time $T$. But if there was a farmer that just finished interviewing at the same time as farmer $B$, then that farmer is also a for interviewing Bessie. Generalizing this, for any farmers that finished interviewing simultaneously, they are candidates. So we know the final farmer and all candidates for it; we'll now go backwards to consider all previous events.

$For any farmers $K$ that finished interviewing at the same time (at times $T$) as farmer $B$, each of them could have interviewed Bessie. Ay farmers that finished with those farmers before time $T$ could also have taken the spot of farmer K. Therefore, those farmers are also viable candidates. We would repeat this process on those farmers over and over again to find all possible farmers.

Do this by connecting two farmers $i$ and $j$ with an edge with weight $t$, given that at time $t$ they simultaneously finish interviewing a cow. Let's say that farmers $1,2,3$ all finish at some time. To avoid drawing an edge between every pair of farmers, which could amount to $N^2$ edges, just draw $1\rightarrow{2}$ and $2\rightarrow{3}$. All farmers are still reachable this way. After this, start from node $B$ and go through the graph. If there is an edge with weight $\le T$, then that farmer is ok. Generalizing this, find the maximum time that each farmer can become a candidate. Assume it's $t_i$; in this case, we can only traverse edges from this node with time $\le{t_i}$. Use a small modification of Dijkstra to calculate.

Time complexity: The initial simulation takes $O(NlogK)$ and there are at most $N$ edges, so the runtime is $O(Nlog(N+K))$.

The extension: I think just count the number of adjacent edges for each farmer $i$ such that it's $\le{t_i}$; this is the weight of the farmer and you can compute probability this way (but not tested).

## 3. The 'Winning' Gene
I actually said that I would never do this problem, but I ended up solving it today for no reason.

The difficulty is figuring out the order of iteration. First, iterate over $L$. For each substring $i$ of length $L$, find the maximum length $k$-mer such that this is the last string in the $k$-mer, and such that it's lex. min. This maximum length is $l_i$. Do the same this on the right, such that this string is the first string in the $k$-mer and such that it's lex. min. Call this $r_i$. Now, it can be said that for any string in the range [$l_i,r_i$] containing $i$, string $i$ is the lex. min string. So the position of $i$ contributes to any $K$ satisfying $L\le{K}\le{l_i+r_i}$. Sum all the ranges with difference arrays to find the value of $(K,L)$ for each $K$, and add it to the answer. The time complexity is $O(N^2)$, but only after some other things get sorted out.

First: finding $l_i$ and $r_i$. This can be done with a 2p/dp algorithm, but it requires us to compare two strings in $O(1)$. Do this by going through each pair of strings and storing the first index that they're different, which allows us to compare any two strings of the same length. This is also done through algorithm for which it's helpful to know dp (see Gold Minimum Longest Trip). 