# USACO Gold 2016 January

## 1. Angry Cows
Do a dp on the left and right ($l_i,r_i$) to find the smallest radius such that a cow launched at this position will destroy all haybales to the left/right. For the left side, $dp_i$ is either $dp_{i-1}$ (if possible), or the maximum of $dp_{i-1}+1$ and $x_i-x_{i-1}$. The right side is calculated in the same way.

The initial radius is $[x-R,x+R]$. The two outermost haybales in this explosion will be the most effective, so fix that $[L,R]$ haybale range. The minimum power needed for a range is the maximum of these three values: $(x_R-x_L)/2$, $r_R+1$, and $l_L+1$. 

Fix $L$ and we have to consider all $R>L$. The two values $(x_R-x_L)/2$ and $r_R+1$ have different calculation values; we can store all $x_R$ in a multiset and $r_R$ in another multiset, and then extract the minimums to do calculation. We can only insert either $x_R$ or $r_R$ for each $R$, because inserting both values into the multisets will treat them independently (which is not good). $r_R+1 \ge (x_R-x_L)/2$ until $L$ reaches $x_R-(r_R+1)$, so we can insert $r_R$ until that point, then remove it and insert $x_R$ instead. So, it takes $O(NlogN)$.

btw, editorial has interesting solutions. It uses greedy 2p to avoid the last paragraph, and also has a nested binary search solution. The nested binary search solution can be reduced by using the dp arrays instead of a second binary search.