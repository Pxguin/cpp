# CSES Sorting and Searching

## Apartments
Each person has a range $[x-k,x+k]$. Sort all ranges by endpoint. Then go through each range, and assign this person to the smallest untaken apartment that fits inside this range. This is a correct greedy solution because our goal is to maximize the amount of people, so if we can assign some apartment to this person, then we might as well assign it. We want to assign the smallest apartment because we are processing the ranges from low to high, and so we want to save the larger apartments for later people. $O(NlogN+MlogM)$ with two pointers.

## Ferris Wheel
Go through people from heaviest to smallest. It's optimal to the current person with the lightest untaken person if possible. We should see that this is done through two pointers, and that the remaining people we consider forms an $[l,r]$ range. So it's never optimal to pair up person $r$ with anyone heavier than person $l$, because even if they can pair up, then any other person inside the $[l+1,r+1]$ range could also pair up with that other person as well (i.e., there's no point). $O(NlogN)$.

## Restaurant Customers
This is a pretty classic problem. Maintain a scan line across the sorted endpoints and keep track of a counter for how many ranges are currently active. When you reach the start of a range, add one to the counter because this range is active, and when you reach the end of a range, subtract one from the counter because this range is no longer relevant. The complexity of the algorithm comes from sorting, which takes $O(NlogN)$.

## Movie Festival
Also classical. We want to constantly pick the event that finishes the earliest, because it gives more room for future events. So initialize a variable $t=0$ as the time we finished watching the last movie. Then sort all movies by ending time and then go through each of them; if we can watch this movie, then just watch it, and then update $t$ because this movie now becomes the last movie that we watched. So, $O(NlogN)$.

## Sum of Two Values
Sort the array and use a 2p method. Let the pointers be $l$ and $r$. If $a_l+a_r=X$, then we have found a solution. If $a_l+a_r<X$, then we must increase the sum so increase $l$ by $1$. Else, $a_l+a_r>X$, so we must decrease the sum by decrementing $r$ by $1$.

$O(NlogN)$ time complexity.

## Stick Lengths
The most optimal length is the median of all the sticks. For an explanation, see the first paragraph of Sliding Window Cost (a problem in this same section). Sorting gives the $O(NlogN)$ complexity.

## Playlist
Solve with 2 pointers. Iterate over every left endpoint for a sequence, and for each one find the maximum right endpoint such that no two values repeat. First, the repetition can be maintained with a set. Second, the maximum right endpoint must monotonically increase for each left point; if you increase the left endpoint (and remove values from the sequence), then it's impossible that the maximum right endpoint will decrease with it. Because of the set, it takes $O(NlogN)$.

## Towers
Iterate over blocks high to low, and keep track of the size of the last block of all towers so far. Because we have to use up all blocks anyway, then this block, out of all towers that it can be placed on, should be added to the tower with the largest last-block size. If none exist, make a new tower. This can be done with a multiset in $O(NlogN)$. Also note that this algorithm is the crux of the problem of finding the minimum amount of increasing subsequences needed to fully cover a sequence (which simplifies to the length of the longest non-increasing subsequence).

## Nested Ranges Check
Well my IOI Empodia solution works on the official test data but fails on the codeforces IOI archive extra tests, so I'm busy debugging that. This nested ranges check algorithm is part of my solution and I seem to have done it correctly because it works on the CSES tests. 

Sort all ranges by increasing $l$, then by decreasing $r$ in the case that $l$ is the same. 
Iterate over ranges in this order. To check whether a range is contained inside another one, store the maximum $r$ value so far (call it $R$) and if this range has $l \le R$ and $r \le R$ then it is contained.
To check whether a range contains another range, store a stack of ranges. When you add a new range, pop elements from the stack while those ranges contain this one; those ranges contain this range. The elements left in the stack at the end don't contain any ranges inside them.

## Room Allocation
Store a priority queue (set in my solution) of the departure times of each active person. Process people by arrival time. We want to first check if any rooms have opened up; in other words, pop the top of the priority queue while it's less than the current arrival time. After this, assign this person a room and add it to the priority queue. The answer is the maximum size of the priority queue at any given point, and it's calculated in $O(NlogN)$.

## Tasks and Deadlines
When we finish a task $i$, then we effectively lose $d_i$ revenue for this task and all future tasks. So it's clear that we want to prioritize the tasks with lower $d_i$. Sort all tasks and calculate the answer in $O(NlogN)$.

## Sum of Three Values
Here is technically a three pointer solution. Iterate over all possible values of the left value, $l$. Then, just run the two pointer solution for all $i>l$, with the goal to get a sum of $X-a_l$.

## Sum of Four Values
We can decompose the four element sum into a two pair sum, and then the goal is to find two pairs with sum adding up to $X$, such that their indices don't overlap.

I had a very dumb brute-force check in mind (store at most 4 different pairs for each possible sum value), but fortunately I found a more elegant way to do it. Iterate over a midpoint $M$ in decreasing order, and only keep track of all pairs $(c,d)$ satisfying $\min(c,d)>{M}$ in a map. We will then test all pairs $(a,M)$ ($a<M$) against the map. This ensures that there is no overlap between any pair $(a,M)$ and any pair $(c,d)$. Using a map actually times out but a hashmap passes, which takes $O(N^2)$.

## Nearest Smaller Values?
?

## Subarray Sums I
All $a_i$ are positive so do a 2p algorithm Ok. This is as helpful as leaving this space blank

## Subarray Sums II
For every prefix sum $A$ find the # of prefix sums to the right of this with value $A+x$, which can be done by maintaining a map of all PS and their frequency, and then subtracting $A$ before calculating its value (for all $A$).

## Subarray Divisibility
Let the prefix sum array be $P$. If $P_i\equiv{P_j}\pmod{N}$, then $\sum_{k=i+1}^j{a_k}$ is divisible by $N$. Store a frequency array over all values of $P$, denoted $F$. $F_i$ counts the amount of indices $j$ satisfying $P_j=i$. For each $F_i$, there are $F_i\choose{2}$ subarrays that can be formed, so add that to the answer.

I think the time complexity is $O(N)$

## Subarray Distinct Values
Maintain a 2p algorithm. Iterate over the left endpoint $l$ of the subarray and find the maximum right endpoint $r$, such that there exist $\le{K}$ distinct values in the range $[l,r]$. Counting the number of distinct values can be done by using a frequency array. Then add $r-l+1$ to the answer; it's the amount of subarrays that work with a left endpoint at $l$.

## Array Division
?

## Sliding Window Median
Store the sliding window and use an ordered set/order statistic tree to select the median (in $O(NlogN)$). Alternatively, binary search on a BIT (which takes $O(Nlog^2N))$. Or follow the solution to the next problem, which describes one in $O(NlogN)$.

## Sliding Window Cost
First pretend we're dealing with only a single window, and sort the array in this window. Assume that the element you are trying to get everything to is at index $X$. Then, fix the sum of nodes with index less than $X$ as $A$, and the sum of nodes with index greater than $X$ as $B$. The amount of nodes with index greater than $X$ is $|A|$ and similar logic for $B$. Now, the total cost equals to $(A-X|A|)+(X|B|-B)$. To simplify things, just have $A$ include index $X$ so all indices belong to either $A$ or $B$, and the formula should still hold.

Now, note that when you increase $X$, you save cost only if $|B|>|A|$. Same goes when you decrease $X$, but for $A$ instead. This general trend points to the fact that the optimal $X$ should be when $|A|=|B|$, or the index of the median. If there are two medians, then either will suffice (in fact, any real number between the two works).

It remains to be able to update $A$ and $B$ across all windows. This requires finding the median, and also all numbers with an index below it and all numbers with an index higher than it. So store two multisets each storing these numbers. When removing or inserting a number, just make sure to balance out the sizes of the multisets by transferring elements between them, such that they each represent everything to one side of the median (this means $|A|=|B|$ if $K$ is even; if $K$ is odd, we are including the median in $A$, so $|A|=|B|+1$). This should give all the information needed for the aforementioned formula. Calculation takes $O(NlogN)$.

## Movie Festival II
We'll instead maintain a multiset of $K$ members and assign the current movie to some member that can watch this movie in time. The optimal strategy is to assign it to the member that finished his last movie at the latest time. Therefore it takes $O(KlogN)$.

## Maximum Subarray Sum II
Basically iterate over every window of length $b-a+1$. Assume the starting point of the window is at index $i$. Then you want to take the maximum $ps[j]-ps[i]$ for $i\le{j}\le(i+(b-a))$, and add it to $ps[i-a]$. In other words, you fix a block of length $a$ from indices $i-a+1$ to $i$, and then extend it anywhere from $0$ to $b-a$ units (obviously, you want to use the extension with the maximum sum). This is simplified to finding the maximum $ps[j]$, then subtracting $ps[i]$ and adding $ps[i-a]$. Taking the maximum $ps[j]$ over every window can be done with a sliding window + multiset, therefore in $O(NlogN)$.