# USACO Gold 2017 US Open

## 1. Modern Art 
https://usaco.org/index.php?page=viewproblem2&cpid=742<br>
https://usaco.org/current/data/sol_art_gold_open17.zip<br>
https://usaco.org/current/data/sol_art_gold_open17.html


## 2. Bovine Genomics
A brute force runs in $O(NM^3)$. Speed it up to $O(NM^2)$ with string hashing (polynomial hashing is overkill but I don't know any other ways ok). However this solution still times out for me so you need to also binary search on the answer to reduce it to $O(NMlogM)$. Also, to avoid using unordered sets I reduced my mod to $999983$ which is fairly small and has a high fail rate, but it still works out fine.


## 3. Modern Art 2
We must be able to store the 1d painting in a stack; otherwise it does not work. So push a color into the stack at the first occurence, and pop it at the last occurence. If when we try to pop it the element isn't the top of the stack, it fails.

Some other observations: 1) The case 12121 should produce $-1$, so we need to make sure that if we push an element into the stack it doesn't show up again at a point where the stack has a larger size. 2) If there is a $0$ then the stack must be empty. 3) The answer is simply the maximum size of the stack at any point.