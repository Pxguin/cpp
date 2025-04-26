idk how i will format this

## 502. IPO
Out of all projects we can start, pick the one with the highest yield. Repeat this process $K$ times, and do it by maintaining two priority queues.

## 1453. Maximum Number of Darts Inside of a Circular Dartboard
[USACO Guide Solution](https://usaco.guide/problems/lc-maximum-number-of-darts-inside-of-a-circular-dartboard/solution). 

Extra notes for the entrance angle: note that $\alpha$ is in terms of the unit circle and thus equal to $a-b$, not $b-a$ as stated in the editorial. The $\tan^{-1}$ function needs to return in the range $[-\pi,\pi]$ thus use atan2 (in c++). It finds the angle of $a$ in reference to the unit circle and moves $-b$ radians, thus giving $\alpha$. $\angle{PQL}$ is right due to the inscribed angle theorem.