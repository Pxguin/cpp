# USACO Gold 2020 January

## 1. Time is Mooney

Assume $C=1$ and all $m_i==1000$. This gives us the upper bound on the number of days (denoted $D$) that we can travel before inevitably losing money, $1000$ days. Then we can just define $dp[i][j]$ as the maximum amount of money we have if we're on day $i$ in city $j$. $dp[i+1][a]=dp[i][j]+m_a$ for all $a$ adjacent to $j$. We must end the trip at the first city but can end it at any day, so take the maximum of all $dp[i][1]-Ci^2$ for all $0\le{i}\le{D}$. Time complexity is $O((N+M)D)$.


## 2. Farmer John Solves 3SUM

Idk how I messed this problem up, it's quite easy ngl. We can iterate over all $(N^2)$ ranges and treat the endpoints of the range $i$ and $j$ as two of our three values. The third value must be $-(s[i]+s[j])$ for the sum to equal $0$ so we just count the frequency of that value in the range. Denote this frequency as $val[i][j]$.

For any given range $val[i][j]$, any range containing $i...j$ must also contain those triples with endpoints $i$ and $j$. In other words for every range $R$ we must add its value to all ranges containing $R$. This follows from a prefix-sum ish relationship where $ans[i][j]=val[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]$. But it is also akin to range DP in that we must process ranges in increasing order of length. The complexity is just $O(N^2)$.

Notes: it is easy to come up with $O(N^2log(N^2))$ solutions; in fact I came up with two of them but they obviously TLE. Also for the frequency array I originally used an unordered map but that both TLE'd and MLE'd, whatever happened there I do not know.