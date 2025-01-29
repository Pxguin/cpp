# USACO Silver 2016 Feb

## 1. Circular Barn
The cows in each room move to form a range in the final configuration. Let this range, for which exactly one cow from room $i$ will move to each room contained within, be $[l_i,r_i]$. We can say that optimally, the ranges are disjoint. Also, for all $i$, the range for $i$ directly proceeds the range for $i-1$, and is directly before the range for $i+1$. This is akin to how the cows move: the cows for barn $i$ will move together, and their final positions will form a range. 

We have an algorithm now: first, fix the value of $r_i$ for any $i$. We'll then proceed as follows:
 - Let the current room we're assigning to be $j$ (initialized to $r_i$), and the current range we're assigning be $i$. Also let the current cost be $C$.
 - If we have completed assigning cows to range $i$, then the range for $i-1$ must directly proceed $i$, so we set $i$ to $i-1$.
 - Otherwise, we assign a cow from room $i$ to room $j$, and move it from $i$ to $j$, so add $d^2$ to $C$ which is the distance that a cow in room $i$ has to move to get to room $j$. After this, decrease $j$ by $1$ because the next room is $j-1$.

When we finish assigning all ranges, compare the current answer with $C$ and take the minimum.

We check for $N$ possible values of $r_i$, and each check takes $O(N)$, so the total time complexity is $O(N^2)$.

RETROSPECT: I WOULD DEFINITELY CHECK OUT THE OFFICIAL SOLUTION BECAUSE MINE IS COMPARATIVELY OVERKILL
Also, I'm not sure if my solution is 100% correct because the test data is very very weak.


## 3. Milk Pails
Create a node $(A,B)$ representing if we can get $A$ units of milk in the first pail, and $B$ units in the second pail. Run a BFS from $(0,0)$ and only consider nodes with a distance $\le{K}$ away from the source, as we can only repeat the operation at most $K$ times. We can figure out the nodes we can transition to from $(A,B)$ by trying each valid operation. For each valid node $(A,B)$, the value of $|M-M'|=|M-(A+B)|$, and so we can compare it with the answer and take the minimum result. So, the time complexity is $O(XY)$ (although $O(XYK)$ would also have passed).

If at any point $j=i-1$ and we haven't finished range $i$, then we are dealing with the case where $[l_i,r_i]$ is composed of two disjoint ranges, so terminate the process.