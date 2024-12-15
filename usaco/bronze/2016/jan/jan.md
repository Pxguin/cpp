# USACO Bronze 2016 Jan

## 1. Promotion Counting
Keep a running counter $c$ of how many cows are being promoted. At first, initialize it to the amount of cows who join during the contest. Then move through each division. First, add the number of "before" cows to $c$ because these many cows may promote to the next division. Then, subtract the amount of "after" cows because these many cows will not promote to the next division; they stop at this division. After this, output the counter $c$ because all of these will promote to the next division. $O(N)$ where $N$ is the number of divisions.