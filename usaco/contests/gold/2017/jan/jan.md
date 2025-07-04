# USACO Gold Jan 2017

## 1. Balanced Photo

Coordinate compress, then maintain two BITs to compute for every cow the amount of taller cows on the left and right sides, respectively.

(do this with complementary counting: # of current cows - # of shorter/same height cows = # of taller cows)

## 3. Cow Navigation
BFS in $O(16N^4)=O(N^4)$ (this is a good problem).