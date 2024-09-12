# USACO Gold 2020 January

## 1. Time is Mooney

Assume $C=1$ and all $m_i==1000$. This gives us the upper bound on the number of days (denoted $D$) that we can travel before inevitably losing money, $1000$ days. Then we can just define $dp[i][j]$ as the maximum amount of money we have if we're on day $i$ in city $j$. $dp[i+1][a]=dp[i][j]+m_a$ for all $a$ adjacent to $j$. We must end the trip at the first city but can end it at any day, so take the maximum of all $dp[i][1]-Ci^2$ for all $0\le{i}\le{D}$. Time complexity is $O((N+M)D)$.

## 2. Farmer John Solves 3SUM

Idk how I messed this problem up, it's quite easy ngl. We can iterate over all $(N^2)$ ranges and treat the endpoints of the range $i$ and $j$ as two of our three values. The third value must be $-(s[i]+s[j])$ for the sum to equal $0$ so we just count the frequency of that value in the range. Denote this frequency as $val[i][j]$.

For any given range $val[i][j]$, any range containing $i...j$ must also contain those triples with endpoints $i$ and $j$. In other words for every range $R$ we must add its value to all ranges containing $R$. This follows from a prefix-sum ish relationship where $ans[i][j]=val[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]$. But it is also akin to range DP in that we must process ranges in increasing order of length. The complexity is just $O(N^2)$.

Notes: it is easy to come up with $O(N^2log(N^2))$ solutions; in fact I came up with two of them but they obviously TLE. Also for the frequency array I originally used an unordered map but that both TLE'd and MLE'd, whatever happened there I do not know.

## 3. Springboards

An $O(N^2)$ simple dp is on the right track, which requires sorting the points by x and then y. In the dp we consider every springboard from every springboard, so each transition is $O(N)$ - to speed up the algorithm we need a faster way to query this. 

Assume we're at a point $(a,b)$. Then for all candidates $(c,d)$, that is, $(x_2,y_2)$ points such that $c\le a$ and $d\le b$, we can add a delta to their dp values to get them all to the same point (the origin), which then allows us to calculate the answer by taking the min value. (Alternate explanation with math) we want to minimize $(a-c)+(b-d)+D$ where $D$ is the dp value for $(c,d)$. Rearrange the equation to $(a+b)-(D-c-d)$, so we want to minimize $D-c-d$.

This works but we still have to find all possible points $(c,d)$. Because we over x iterate in increasing order, we, by default, establish $c\le a$. So reduce it to finding the minimum $(D-c-d)$ value out of all points $d\le b$. It is easy to use a segment tree to do this but you can also use a set/map (see usaco guide [max suffix query with insertions only](https://usaco.guide/adv/springboards)). I will quickly cover it here. Either way it takes $O(NlogN)$.

(Set solution). Put all points $(d,D-c-d)$ into a set. For the sake of clarity I'll reduce the point to a simple $(c,d)$. Then when querying a springboard $(a,b)$ we want to find the minimum $d$ over all pairs $c\le b$. Note that if there's two pairs in the set $(A,B)$,$(C,D)$ with $A\ge C$ and $B\ge D$ then we can ignore $(A,B)$. As a result, the first element of each pair in the set will be decreasing and the second element will be increasing. So when inserting a pair $(A,B)$ into the set check if any $(C,D)$ satisfy $A\ge C$ and $B\ge D$; if it exists then $(A,B)$ doesn't belong in the set. Otherwise add it and pop pairs $(C,D)$ while $C\ge A$ and $D\ge B$. When querying a springboard $(a,b)$ just take the first pair $(c,d)$ such that $c\le b$ - it will have the minimum $d$ value.