# ICPC Northern Eurasia Finals 2023

## A. Accumulator Apex
Very similar to Codeforces $1734D$, but instead of two lists there are $K$ lists, and the goal is to maximize the result. The same algorithm can be applied, but instead of checking against two lists we have to check against all $K$ lists. To speed this up use a priority queue sorting in descending order. 