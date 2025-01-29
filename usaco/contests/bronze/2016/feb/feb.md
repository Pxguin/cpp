# USACO Bronze 2016 Feb

## 3. Load Balancing
Go through all possible x-fences and y-fences. If we have two cows, then any x coordinate between the two x-coordinates of the cows will divide them the same. So for each gap between x-coordinates of cows, any vertical fence in that gap yields the same effect. Therefore, for each gap only consider one fence. Then go through all vertical and horizontal fence combinations, and for each one go through all cows to count how many are in each quadrant. $O(N^3)$.