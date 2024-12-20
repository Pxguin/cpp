# USACO Silver 2016 US Open

## 1. Field Reduction
No matter which $3$ cows we remove, there are only $4$ possible coordinates for each of the new borders. Precisely, these are the first four unique coordinates of the cows starting at that border (so left border = four smallest unique x-coordinates). Try all of them, and then for each configuration, iterate through all the cows and update the new enclosure. Time complexity: $O(N)$.