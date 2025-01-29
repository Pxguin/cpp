# USACO Bronze 2016 US Open

## 1. Diamond Collector
Sort all diamonds. The answer must be a range in the sorted array, so fix all left points, and then brute force to find the maximum possible right point such that the left (smallest) and right (largest) diamonds do not differ by more than $K$ in size. $O(N^2+NlogN)$.