# USACO Bronze 2024 January

## 1. Majority Opinion
As long as we can get some subsegment of size $\ge{2}$ where all cows there like the same type of hay, then it is possible to make all cows like that type of hay by inducting cows that are adjacent to the subsegment one by one. 

Assume we want to get that initial subsegment to like hay $H$. Then it's always optimal to have the left and right endpoints of the subsegment be cows who prefer hay $H$, as to minimize the number of cows who don't like $H$. Therefore, split the cows into arrays $T$ where $T_i$ contains the indices of all cows who like hay type $i$. All valid subsegments can then be tested in $O(N^2)$.

The formula for testing if a subsegment is valid is as follows: we are trying to build a subsegment between two indices in one of the arrays $T$. Let the indices in the array $T$ be denoted $t_i$ and $t_j$, and let the indices in the original array be denoted as $h_i$ and $h_j$. We can say that the subsegment works if $2(t_j-t_i+1)>h_j-h_i+1$, or that there are a majority of cows that like that hay type. Rearrange to $2t_j-h_j+1>2t_i-h_i$. So when iterating over all indices $j$ in the array $T$, store the minimum $2t_i-h_i$ for $i<j$, and then just check if the aforementioned equation is satisfied. This runs in $O(N)$.

Alternatively, it can be said that for any working subsegment, there must exist a smaller, working subsegment of length $\le{3}$ contained inside. Otherwise, the best that can be done is having only half of the cows like the same type of hay. 

## 2. Cannonball
It's as easy as simulating the process. We need to keep track of which targets have broken though to ensure we count the answer properly. The problem statement doesn't mention it but $v_i$ can equal $0$, so we need to watch out for the case where Bessie bounces infinitely (this will be if $v_i=0$ and she reaches this square twice with the same power and direction, because then we can assume there's an infinite loop). Otherwise, Bessie's speed must continue increasing so she'll leave the number line at some point - at most after $O(NlogN)$ operations. 