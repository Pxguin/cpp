# CSES Math

## Exponentiation
Use binary exponentiation to find the answer.
$a^b$ is equivalent to $x*a^b$ when $x = 1$. If $b$ is even then simplify to $x*(a^2)^{b/2}$ (square $a$ and halve $b$), and if $b$ is odd then simplify to $xa*a^{b-1}$ (multiply $x$ by $a$, subtract $1$ from $b$ to make it even). When $b=0$ then we can stop because $a^b = 1$, and so the answer is equal to $x$. Over all queries it takes $O(NlogB)$ time.

## Exponentiation II
No clue how this works — I just copypasted code

Update: it uses a byproduct of Euler's totient theorem I think.

## Common Divisors
Iterate through all possible values of the GCD. If more than two numbers divide this candidate GCD, then it's valid. So store a frequency array of all numbers $f$, and go through each multiple $j$ of the candidate. Sum up $f_j$, and the resulting sum gives how many numbers divide this number. If it's $\ge{2}$ then we've already established that it works, so just return the largest number than works.

The time complexity is $O(XlogX)$.

## Sum of Divisors
Letting $f(D)=\lfloor{N\over{D}}\rfloor$, the answer is $\sum_{D=1}^N D*f(D)$. $f(D)$ and $D$ are inversely proportional so fix them both up to $\sqrt{N}$ for an $O(\sqrt{N})$ solution.

Specifically:
 - Fixing $D$: calculate $f(D)$, and add $D*f(D)$ to the answer.
 - Fixing $f(D)$, denoted $P$: find the largest range of numbers $[l,r]$ such that $f(x\in[l,r])=P$. Add $P\cdot(l+(l+1)+\dots+r)=P\cdot(l+r)(r-l+1)/2$ to the answer. 
 - $[l,r]$ can be found by the following: $P=\lfloor{N/D}\rfloor$, so $P\le{N/D}<P+1$, meaning that $\lfloor{N\over{P+1}}\rfloor<D\le{\lfloor{N\over{P}}\rfloor}$. This gives us our desired values.

Make sure that you don't overcount any $D$. Also, combining the above two cases together, it's actually easier to say that only $2\sqrt{N}$ distinct values of $f(D)$ exist, so we can do an algorithm like in [Loan Repayment](https://usaco.org/index.php?page=viewproblem2&cpid=991).

## Prime Multiples
For every prime, compute all its multiples $\le N$ and store these in a set.
The answer is the size of the union of all the sets, which can be computed with the Inclusion Exclusion Principle. It takes $O(2^K*K)$.

## Candy Lottery
An expected value problem. The probability of getting a maximum of $M$ is $({M\over{K}})^N-({{M-1}\over{K}})^N$: this is the chance of getting $N$ values at most $M$ minus the chance of getting $N$ values less than $M$. The runtime is $O(NK)$ although you can achieve $O(KlogN)$ with binary exponentiation.

$\begin{equation}
E[X] = \sum_{x=1}^{i=k} ((\frac{x}{k})^n-(\frac{x-1}{k})^n)*x
\end{equation}$
$\begin{equation}
E[X] = \frac{-(1^n+2^n+\cdots{+(k-1)^n})+k(k^n)}{k^n}
\end{equation}$
$\begin{equation}
E[X] = k-\frac{1^n+2^n+\cdots{+(k-1)^n}}{k^n}
\end{equation}$
 I could only do it with python because the numerator overflows in cpp, and if I just calculate the normal equation then there's decimal precision issues.