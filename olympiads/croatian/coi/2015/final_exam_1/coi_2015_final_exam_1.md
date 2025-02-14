# COI 2015 Final Exam #1

## 2. Žarulje (Light Bulbs)
Let the "off range" refer to the range of lightbulbs that are currently turned off. Consider the lightbulb $i$ at the very left of the off range. As long as the right lightbulb doesn't have a strictly smaller energy cost than this, then we can continue turning off the right lightbulb.

More formally, find the nearest (strictly) smaller values to the left and right of each lightbulb $i$. Let these values be $L_i$ and $R_i$. They give the range of lightbulbs we can turn off if $i$ is at the left/right of the off range.

We can see that if the right range for a lightbulb $i$ intersects the left range for a lightbulb $j$, and $A_i=A_j$, then from any $i<p<j$ we can reach the state where the off range is $[i,j]$. Now we have two options: either turn off $i$ or turn off $j$. These are the only states where the answer can increase, so it suffices to only maintain these ranges. 

Following from the above, call $i$ and $j$ reachable if the above holds. We can form components of all mutually reachable lightbulbs. By the nature of the ranges, each component is of maximum size possible and each lightbulb belongs to exactly one component.

Answers for components can be calculated independently and then multiplied together. For a position $p$ in a component, the amount of ways to turn off this component from that position is equivalent to $L+R\choose{L}$, where $L$ is the amount of lights in this component to the left of $p$. $R$ is defined similarly. Letting the component size be $S$, we only need to consider $S+(S-1)$ distinct values of $p$ (either on a lightbulb, or between two lightbulbs) and can just do range multiplies (similarly to difference arrays) to quickly update for all values of $p$ in this component.

We are missing a side case. Let's say that two indices $i$ and $j$ ($A_i=A_j$, $i<j$) are in separate components, but $R_i=L_j$. In this case, setting $p=R_i$ combines these two components together into one. Clearly, at most one of these indices exists between two adjacent components of the same energy level, so at most $N$ of these indices need to be dealt with.

We have effectively precalculated all queries. The time complexity of this solution is therefore $O(NlogN+K)$.