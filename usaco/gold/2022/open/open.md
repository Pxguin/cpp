# USACO Gold 2022 US Open

## 1. Apple Catching
A cow at position $x_i$ at time $t_i$ can catch an apple $x_j$, $t_j$ if the following holds: $|x_i-x_j|\ge{t_i-t_j}$ where $t_i\ge{t_j}$. If $x_i$ is treated as the x axis and $t_i$ as the y axis, then a cow at $(x_i,t_i)$ can catch any apples satisfying $y-t_i\ge{|x-x_i|}$. Rotate the plane by $-45°$ and scale by $\sqrt{2}$ so that a point at $(x,y)$ becomes $(x+y,y-x)$. Then for a cow at $(x_i,t_i)$, it can catch all apples $(x,y)$ if $x_i\le{x}$ and $t_i\le{y}$.

Iterate over all apples by x and then by y. It can be said that out of all available cows that can catch each apple, the most optimal assignment is to the cow with the greatest $y$ value. In other words, we pick the cow with the strictest $t_i$ constraint. The reason this works is only because it is assumed that we have already assigned all apples that have a lower x and y value compared to this one. The runtime is $O(NlogN)$.