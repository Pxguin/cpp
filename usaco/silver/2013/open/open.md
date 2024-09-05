# USACO Silver 2013 US Open

## 3. Luxury River Cruise

A brute force is to simulate in $O(KM)$. But in $O(NM)$ time we can simulate the sequence of moves for each port to figure out where we end up for each one. Take the sample: if we are at the first port then after $M$ moves we reach port $2$. If we are at the second port then after the sequence of length $M$ we reach port $3$. In this way we can simulate $M$ moves in $O(1)$, reducing the complexity to $O(K)$. 

This next step takes advantage of the fact that there are only $N$ ports, meaning that we will find a cycle within $N$ moves. If we ever manage to reach this cycle then we'll just predictably loop over it again and again - so we can just modulo by the length of the cycle. If you're confused, similar applications are used in the problem Swapity Swap (Bronze 2020 Feb) and Blink (Bronze 2013 Open). The $O(K)$ is reduced to $O(N)$, but the final runtime is still $O(NM)$ because of the initial simulation.