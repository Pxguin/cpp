# USACO Silver 2024 Feb

## 2. Test Tubes
This problem is not my type, so there's a reason why I avoided it for so long. Despite a simple greedy strategy, it still proved to be a rigorous implementation, until I rewrote it with comments to get the solution that I have now.

First compress the liquid in the tubes so that a block of $1$'s becomes a single $1$, and same for $2$'s. We can say that there are two starting moves: either we start by pouring the first tube, or we start with the second tube. If we start with the first tube, then we have two other options if the liquids at the tops of tubes A and B are the same: pour into the second or third tube. But if this is the case, then it's always optimal to pour into the second tube, because it may improve the answer, and, if it doesn't, you won't lose anything from doing this. Otherwise, pour into the third tube.

After this first move there are two other actions we can take: either we filter tube $A$ or filter tube $B$. Filter means that we empty the tube until there is only one color of liquid remaining. Tube $A$ will be filtered into $B$ and $C$ and same for $B$. After these actions, then a greedy strategy holds. But for these four possibilities, brute force will suffice.

Now we can say that tube $A$ has only a single color inside of it. If tube $C$ has the same color as tube $A$, then pour $C$ into $A$. So after this, tube $A$ and $C$ should be able to hold different colors of liquids inside them, meaning that we are able to filter $B$. The same process as above will work.

Running in $O(N)$ per test case, the final runtime is $O(TN)$.