# USACO Platinum 2016 Jan

## 1. Fort Moo
Fix the height and y-position of the left boundary. Now iterate through all the x-values that the left boundary could be placed on. If we reach an x-coordinate that is a valid placement for this boundary, place it here, and now we have to find a candidate for the right boundary. So iterate forwards while the top and bottom squares are empty (so the fort is still valid). Whenever we reach an x-coordinate such that it's a valid placement for the right boundary, then compare the current area with the answer and continue forwards. When we stop iterating, meaning the fort is no longer valid, then update the initial pointer to this location because we can say that all future left boundaries must be after this point. (see code for details)

Runtime is $O(NM(N+M))$ if we use prefix sums to determine whether a space is empty or not, although I'm decently sure that prefix sums can be used to get an unintended $O(N^2M^2)$ algorithm...