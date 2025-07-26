# USACO Gold 2017 US Open

## 1. Modern Art
For each color, find the strictest rectangle that could have been painted for that color. It's always optimal to do this because it allows flexibility for when this color could have been painted. After this, if there exists any cell that is an intersection of two or more rectangles (calculate with 2d prefix sums), then the final color of the cell must have been painted over another color; therefore, that color can't have been painted first (and mark it as such). At the end, any colors that we haven't marked off could have been first. Also, make sure to take care of the side case where there is only one visible painted rectangle. So, $O(N^2)$.

## 3. COWBASIC
Suppose a loop runs only once, and modifies two variables. Let's let their values before the loop proceeds be $a$ and $b$, and the values after the loop ends be $a'$ and $b'$. We can express each of $a'$ and $b'$ as a linear combination of $a$ and $b$, thus mapping the loop into a matrix.

If the loop runs $x$ times, then raise the mapping for one iteration to the power of $x$.

If there are nested loops, then after we get the matrix for the inner loop it is still necessary to combine it into the older loop. The inner loop matrix is equivalent to many simultaneous variable assignments, so it can be handled in the same way as before.

Let's enclose the entire program in a loop that runs once. Thus we get a matrix corresponding to the whole program. Since no variable is referenced before defined, then it's guaranteed that each mapping in this matrix won't be an expression (i.e., the mapping for each variable is just its final value). So no extra work is needed.

Given that the amount of lines is $N$, the length of each line is $M$, and the maximum amount of reps for a loop is $K$, then the time complexity is roughly $O(N^2{M\over{3}}logK)$.