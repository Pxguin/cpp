# USACO Bronze 2024 January

## 2. Cannonball
It's as easy as simulating the process. We need to keep track of which targets have broken though to ensure we count the answer properly. The problem statement doesn't mention it but $v_i$ can equal $0$, so we need to watch out for the case where Bessie bounces infinitely (this will be if $v_i=0$ and she reaches this square twice with the same power and direction, because then we can assume there's an infinite loop). Otherwise, Bessie's speed must continue increasing so she'll leave the number line at some point - at most after $O(NlogN)$ operations. 