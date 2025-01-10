# ?

## H. Sheet Music
Compress each song into the following graph. Let $b_i$ represent the relationship between $a_i$ and $a_{i+1}$. For a song $a$, if $a_{i+1}>a_i$, then $b_i$ is an upstroke /. If $a_{i+1}<a_i$, $b_i$ is the downstroke \\. Otherwise $b_i$ is a flatline —.

Our goal is to make sure that the pitches in a song stay within the bounds $[1,K]$. Flatlines don't affect the current pitch so remove them; we can add them back in the end. If we know the number of valid songs of length $i$, without flatlines (denoted $T_i$), then we can add in the flatlines with stars and bars. Specifially, we add $N-i$ remaining flatlines at any of $i$ positions, so the amount of ways to add flatlines is ${N-1\choose{N-i}}$.

The answer is therefore $\sum_{i=1}^N{T_i\cdot{N-1\choose{N-i}}}$. Now, it remains to calculate all $T_i$ values.

A song without flatlines is valid, if in its graph, no symbol appears more than $K-1$ consecutive times. This means we can calculate with dp. If $T_i\le{K}$, then any graph works, so $T_i=2^{i-1}$. Otherwise, we can transition from any of $T_{i-y}$ satisfying $0<y<K$, by taking any of those graphs and then appending $y$ consecutive equal symbols. Thus, $T_i=\sum_{y=1}^{K-1}{T_{i-y}}$.

After factorial precomputation, the time complexity is $O(N)$.