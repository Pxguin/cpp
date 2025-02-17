# USACO Silver 2017 Dec

## 1. My Cow Ate My Homework
Testing for all $K$ and simply comparing the averages will work, if we can figure out an efficient way to retrieve the minimum for each $K$. We can do this by iterating over $K$ in reverse order as to make sure the set assignments we retrieve the minimum from for some $K$ is a subset of all the assignments we retrieve the minimum from for all future $K$ (this means updating the min is really easy). $O(N)$