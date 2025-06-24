# USACO Plat 2020 Jan

## 3. Falling Portals
Transform each world $i$ into a line function $f_i(t)$ that returns the y-coordinate of the world at time $t$.

### Case 1: $a_i<a_{q_i}$
We want to find a function for $i$, denoted $p_i(t)$, that returns the maximum y-coordinate the cow starting at world $i$ can have at time $t$. This function is defined for $t\in[0,\infty)$, and the x-coordinate of the intersection of this function with line $f_{q_i}(t)$ is the answer.

Next is how to find this function. When traversing from $i$ to $q_i$, all worlds that are visited (in chronological order), excluding $q_i$, have strictly decreasing speeds.

Idea: consider all lines with lesser or equal speed, and we can see that the upper convex hull of these lines is related to $p_i(t)$. In fact, the upper hull from $[0,\infty)$ is exactly $p_i(t)$ if $f_i(t)$ is the line on the hull at $t=0$.

Going back to the above: if all worlds visited in chronological order have strictly decreasing speeds, then they also have strictly decreasing $a$ values. Considering the set of all lines with lesser or equal $a$ (y-intercept), it's clear that $f_i(t)$ is the line on the hull at $t=0$. So $p_i(t)$ is just the upper hull of these lines, for $t\in[0,\infty)$.

Sort all $a_i$ in increasing order and all queries of the form $a_i<a_{q_i}$ can be answered: the upper hull from $[0,\infty)$ is maintained with a stack in $O(N)$ and binary searching for the intersection point takes $O(logN)$.

Overall, $O(NlogN)$.

### Case 2: $a_i>a_{q_i}$
Similar logic works. In fact, we can simply mirror the lines across the x-axis and use the exact same code to answer these queries.

Total time complexity: $O(NlogN)$.