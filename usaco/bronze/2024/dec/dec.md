# USACO Bronze 2024 Dec

## 1. Roundabout Rounding
Each digit can only round up or down. We can see that by chain rounding, we can only influence the number to round upwards, never downwards. To change the final number, the first digit must round upwards with chain rounding, whereas it rounded down before. Therefore, the first digit must be a $4$. The second digit must therefore round up for this $4$ to round up. If this number is any of $5,6,7,8,9$, then it's fine. After this digit, any future digits can be anything because we have already guaranteed the number to round up.

However, the second digit may not be a $5$; it can also be $4$. Generally, we can see that the number can have any positive length prefix of $4$'s, as long as the first non-$4$ digit is one of $5,6,7,8,9$. All future digits are unrestricted. So iterate over all lengths of numbers $L$. The amount of valid numbers of length $L$ is in the range $[4444\dots{5},4999\dots{9}]$. $4444\dots{5}$ is $L-1$ copies of $4$ followed by one $5$, which is the minimum number possible. The maximum is $4999\dots{9}$, $4$ followed by $L-1$ copies of $9$. So just take the intersection of this range with the range $[2,N]$ and add its size to the answer. We get a time complexity of $O(logN)$ per test case.

## 2. Farmer John's Cheese Block
There are only $3$ configurations for the $1\times{N}$ block, which represents a vector parallel to either the x, y, or z axes. There are $N^2$ possible vectors parallel to each axis, so we should store the amount of empty blocks in each vector in each axis. For each query, update the three vectors that it affects, and if we find that that vector is empty, then add one to the answer. $O(N^2+Q)$ time complexity.

## Comments:
Problem $1$ is quite difficult. It took me probably 30 minutes to figure out the concept but I could not figure out how to check if a number is $\le{N}$ (had to read editorial). Turns out the valid numbers form a range though, which is nice.

Problem $2$ is pretty simple. The giveaway is that once a vector is empty, it stays empty. Also, there are $3N^2$ possible vectors, which is easy to store.

Problem $3$ seems tedious but I may do it sometime...