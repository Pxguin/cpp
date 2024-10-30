# USACO Silver 2023 Dec

## 1. Find and Replace
How can you determine whether the string is unable to be changed?

This is basically a function. We can come to the conclusion that we can treat this as a graph problem: some letters map to other letters, i.e. an edge between two letter vertices. Obviously, the answer increases by one for every edge, but there's also special case in the third test case: $ABCD \rightarrow BACD$. A maps to B, and B maps to A. To solve this, A must be changed to a temporary character. It's important to note that this is only needed when there is a cycle in the graph. Specifically, a temporary character is only needed when there exists such a cycle with no other incoming edges (so the indegree and outdegree of every node is exactly $2$). For example, assuming you have a cycle $A\rightarrow{B}$,$B\rightarrow{C}$,$C\rightarrow{A}$ and the incoming edge $D\rightarrow{B}$. You can replace the edge $A\rightarrow{B}$ with $A\rightarrow{D}$ to break the cycle.

So it is impossible if the initial string is not equal to the goal string, and the goal string contains all $52$ letters.
This is because if the initial string doesn't have all $52$ unique letters, then one character maps to more than one character so it's impossible. If the initial string satisfies this, then every node is part of a cycle, so temporary characters must be used. However, there are no temporary characters left to use, so this doesn't work either.

So initialize the answer to the number of edges. We want to figure out what every character maps to, then check for any cycles without incoming edges. If there is one, then we need to increase the answer by one, because we have to use an extra operation to convert to a temporary character. It runs in $O(|S|+\Sigma^2)$ where $\Sigma$ is the size of the alphabet (there are $\Sigma^2$ edges at max).

## 2. Following Directions
For every sign, all cows passing through that sign obviously must follow the same path, and so end up at the same vat. So when a sign changes, the amount of cows that change paths is the amount of cows that currently pass through that cell. Using this knowledge, we can store a frequency list for every cell, including the vats. 

Then, for every query, we want to erase the old path of the cows, so we take the frequency of the cell $(i,j)$ that we want to flip, and follow the path until we reach a vat. Subtract the frequency of the original cell from every cell along that path. When reaching a vat, we will subtract the frequency times the cost of the vat from the answer, which represents the total cost of feeding all the cows on the path.

After this, we will flip the direction of the sign and trace the new path in the same fashion. When reaching a vat, we add that frequency times the cost, because this many cows are now going to this vat. All in all, the runtime is $O(N^2+NQ)$.

## 3. Moo Route
Bessie's route must have the same number of R's and L's. So, the route can be decomposed into a series of smaller routes which each consist of a sequence of R's followed by a same-length sequence of L's (such as $RRLL$, or $RRRRRLLLLL$). To find the decomposition that minimizes the number of direction changes, it's optimal to constantly select the longest available route. At the end, we can combine all these routes together by first going right $N$ times, then interspersing all these smaller routes while going back left $N$ times. I use a set so it takes $O(TlogT)$, but with some more observations it can be more elegantly and concisely written in $O(T)$ (see the editorial).