# USACO Plat 2017 Jan

## 1. Promotion Counting
Process cows in decreasing order of proficiency such that we guarantee that for each cow $i$, all cows $j$ that have already been processed must satisfy the rule $p(j)>p(i)$. It remains to calculate the amount of these $j$ that are in the subtree of $i$, which is a simple range query (after taking the Euler tour) that can be processed with a BIT. So, $O(NlogN)$.

## 3. Subsequence Reversal
ok this took me too long to debug. I initially was hesistant to go with this solution because it's a weird 4d dp array but everything else I tried failed, so oh well. 

It may be unclear at first that we want to do dp on ranges but it should be clear that this is the best choice because 1) small constraints, so brute force is applicable, 2) reversal of a subsequence is pairing up elements and swapping them, which is very characteristic of range dp problems. Basically, let $dp[l][r][mn][mx]$ be the LIS for the range $[l,r]$, given the minimum of the LIS is $mn$ and the max is $mx$. These extra $mn$ and $mx$ dimensions are necessary (I tried doing it without them...). The base cases are for $r=l$ and $r=l+1$. Aside from them, we can choose to transition like this:
 - For $dp[l][r][mn][mx]$, we can get here by swapping cows $l$ and $r$, and adding either (or both) of them to the LIS. 
 - We can also add cow $l$ or cow $r$ to the LIS without having to perform any swaps.
 - Third, we can do nothing.

There are $N^4$ states, which proportional to the $O(N^4)$ runtime.