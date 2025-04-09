# CSES Geometry

## Point Location Test
$C$ equals the cross product between the segments $\overline{p_1p_2}$ and $\overline{p_1p_3}$. If $C=0$, then the point is on the line. If $C>0$, then the point is to the left of the line. Otherwise, it's to the right of the line.

Time complexity: $O(1)$.

## Polygon Area
Use the shoelace theorem. The area of a polygon with $N$ vertices $(x_1,y_1)\dots(x_n,y_n)$ is ${1\over{2}}\sum_{i=1}^{N}\begin{vmatrix}x_i & y_i \\ x_{i+1} & y_{i+1}\end{vmatrix}$ where $(x_{n+1},y_{n+1})=(x_1,y_1)$. This can be proved by induction.

Time complexity: $O(N)$.

## Polygon Lattice Points
Calculating the number of lattice points on the boundary can be done with some slope math. It's the sum of all $gcd(|x_{i+1}-x_i|,|y_{i+1}-y_i|)$. Finding the number of interior lattice points can be done by reversing Pick's theorem. It runs in $O(NlogD)$, $D$ is the maximum difference between the x-coordinates or y-coordinates of any two points.