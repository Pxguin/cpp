# CSES Math

## Exponentiation
Use binary exponentiation to find the answer.
$a^b$ is equivalent to $x*a^b$ when $x = 1$. If $b$ is even then simplify to $x*(a^2)^{b/2}$ (square $a$ and halve $b$), and if $b$ is odd then simplify to $xa*a^{b-1}$ (multiply $x$ by $a$, subtract $1$ from $b$ to make it even). When $b=0$ then we can stop because $a^b = 1$, and so the answer is equal to $x$. Over all queries it takes $O(NlogB)$ time.

## Exponentiation II
No clue how this works — I just copypasted code

## Prime Multiples
For every prime, compute all its multiples $\le N$ and store these in a set.
The answer is the size of the union of all the sets, which can be computed with the Inclusion Exclusion Principle. It takes $O(2^K*K)$.

## Candy Lottery
An expected value problem. The probability of getting a maximum of $M$ is $({M\over{K}})^N-({{M-1}\over{K}})^N$: this is the chance of getting $N$ values at most $M$ minus the chance of getting $N$ values less than $M$. The runtime is $O(NK)$ although you can achieve $O(KlogN)$ with binary exponentiation.

!!! cses added some shit test cases that reduced the solve rate by 60% because they target inherent decimal inaccuracy. I updated code but it still doesn't work (idc for now, may try fixing later).