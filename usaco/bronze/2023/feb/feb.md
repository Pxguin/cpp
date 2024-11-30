# USACO Bronze 2023 Feb

## 1. Hungry Cow
Simulate the process in increasing order of $d_i$. Assume you have $B$ haybales at day $d_i$ (before eating), and the next point is $d_{i+1}$. The shipment on that day arrives before dinner, so calculate only up to day $d_{i+1}-1$. In this case, Bessie eats $\min((d_{i+1}-1)-(d_i-1),B)$ haybales. After this, add $b_{i+1}$ to $B$ and continue the process. Make sure to also deal with $T$ after all the $d_i$. Time complexity is $O(N)$. 

## 2. Stamp Grid
We're only asked to determine whether it's possible stamp the grid, so we can try all possible stamp locations and rotations. If all the ink spots on the stamp align with ink spots on the canvas, then we might as well stamp this here because it contributes to the answer. If there are some ink spots on the stamp that don't align with the canvas, then we can't use this stamp here. After simulating, just see if each ink spot on the canvas was painted on by some stamp, and if all of them are, then the answer is "YES", and otherwise "NO". It runs in $O(N^2K^2)$ per test case.