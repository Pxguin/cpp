# Balkan OI 2009

## 2. Reading
Simpler problem: Find the number of words with value equal to $N$.

Solution: Define a dp $dp[i][j]$, the number of words with value $i$ and last character $j$. To find all of $dp[i]$, it is only of interest to know $5*26$ dp values: $dp[i-1]$, $dp[i-2]$, $dp[i-3]$, $dp[i-4]$, $dp[i-5]$.

Map into a matrix of size $(5*26)\times{1}$. The first $26$ rows store $dp[i-5]$, the next $26$ store $dp[i-4]$, etc.

The transition: replace the first $26$ values with the second $26$, the second $26$ with the third $26$... the fourth $26$ with the fifth $26$, the fifth $26$ with $dp[i]$. Its easy to construct a map for each row to get a $(5*26)\times(5*26)$ transition matrix.

Original problem: Find the sum of all $dp[i]$ for $0\le{i}\le{N}$. Add in another row into the matrix storing the sum of all dp values so far, and it's updated similarly.

$O((26F)^3logN)$.