# JOISC 2019 Day 1

## 1. Examination
### Solution in $O(Q\sqrt{NlogN})$:
Sort queries by $C$ and students by $T+S$ to take care of the third constraint. For an arbitrary constant $B$, maintain $O({N\over{B}})$ segment trees/indexed sets (if c++). Block $i$ is responsible for the students $[B(i-1),Bi-1]$ (when students are sorted by $S$).

For each query $j$, the constraint $T_i+S_i\ge{C_j}$ has already been fixed. So iterate over each block and count the number of students $i$ satisfying both $S_i\ge{A_j}$ and $T_i\ge{B_j}$. This part runs in $O(B+{N\over{B}}logB)$. Set $B=N/\sqrt{N/logN}=\sqrt{NlogN}$ and the algorithm runs in $O(Q\sqrt{NlogN})$.

### Solution in $O((N+Q)logN+QlogQ)$:
I almost found this solution by myself, technically (got 90% of way there, and then I didn't think it would get anywhere).

If $A+B\ge{C}$ then the constraint $S+T\ge{C}$ is redundant. The amount of students satisfying this query is easily counted in $O((N+Q)logN+QlogQ)$.

If $A+B<C$ then something we can try is to count the number of students satisfying $S\ge{A}$ and $S+T\ge{C}$. This overcounts students satisfying exactly $S\ge{A}$; $S+T\ge{C}$; $T<B$. Note that $S\ge{A}$ is redundant (which is the one thing that I missed).

Every one of these subproblems involves counting the number of students satisfying two conditions, instead of the original three, which is a much easier problem that results in the aforementioned runtime.