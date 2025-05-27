# USACO Plat 2023 Dec

## 2. A Graph Problem
Iterate edges $1$ to $M$

Edge $i$ is $(u,v)$ then use DSU to merge the two components of nodes containing $u$ and $v$

Motivation: because for all nodes $x$ in component containing $u$ (denoted $S_u$), the next edge is edge $i$ (and then it follows the entire path that node $v$ has taken i.e. the entire component of $v$)

How to update $h$:
 - So for all nodes $x\in S_u$, multiply $h_x$ by $10^{|S_v|}$ then add $i\cdot{10^{|S_v|-1}}$ then add $h_v$.
 - For all nodes $x\in S_v$, multiply $h_x$ by $10^{|S_u|}$, add $10^{|S_u|-1}i+h_u$.
 - Do all operations simultaneously

Optimization 1: instead of building $h_x$ (for example) like $1\rightarrow{12}\rightarrow{123}$, build it like $100\rightarrow{120}\rightarrow{123}$. In other words start with the powers of $10$ in place already so that there is no need to multiply $h_x$ by $10^{|S_v|}$. Now the process is to add $i\cdot{10^{N-|S_v|-1}}$ and then $h_v/10^{|S_u|}$ which is done with mod inverse.

Optimization 2: Since it's only addition then small to large merging is ok. If we need to add $a$ to all nodes in $|S_u|$ and $b$ to all nodes in $|S_v|$, and $|S_u|>|S_v|$, then just add $b-a$ to all nodes in $S_v$, merge $S_v$ into $S_u$, and make a note that we need to add $a$ to all nodes in $S_u$ later.

So time complexity is $O(NlogN+M)$.