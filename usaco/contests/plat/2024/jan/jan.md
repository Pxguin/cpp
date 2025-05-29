# USACO Plat 2024 Jan

## 3. Mooball Teams III
Add configurations with horizontal lines: fix line and use combinatorics

Add configs with vertical lines: same thing

Subtract configs able to be separated by both vertical and horizontal line:

Look at brute force: fix vertical line then horizontal line -> speed up the brute force through horizontal lines by simplifying the formula, and computing its delta compared to the previous vertical line; use lazy segtree to efficiently maintain these and compute sum.

$O(NlogN)$
MY SOLUTION IS SUPER SLOW HELP