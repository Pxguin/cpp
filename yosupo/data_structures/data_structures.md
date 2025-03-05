# data structures

## Static Range Sum
Use prefix sums. $ps_i=\sum_{i=0}^i{a_i}$. Then, $\sum_{i=l}^r{a_i}=ps_r-ps_{l-1}$. Calculating prefix sums and answering queries is done in $O(N+Q)$ total complexity.

## Static RMQ
Sparse table ($O(NlogN+Q)$).

## Queue Operate All Composite
When expanding the function, the coefficient on x is the product of all $a_i$. The constant is the sum of values $cb_i$ where $c$ is equal to the product of all $a_j$ satisfying $j>i$. 

So when adding the function $ax+b$ to the back, multiply the current constant by $a$ and add $b$. Multiply the coefficient by $a$. When querying a value, plug it into the simplified expression. When removing a value, divide the coefficient by $a$, and divide the constant by $a$ after subtracting $b$. To do division multiply by the modular inverse of $a$, which is equal to $a^{mod-2}$. So, it runs in $Qlog(mod)$.

## Deque Operate All Composite
There are two new cases now. The first is adding a function $ax+b$ to the front, which is accomplished by adding $b$ times the coefficient to the constant, then multiplying the coefficient by $a$. Removal from the back is easy to handle for the coefficient; then for the constant, subtract $b$ times the coefficient. The time complexity is the same, $Qlog(mod)$.