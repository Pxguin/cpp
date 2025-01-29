# USACO Silver 2017 January

## 3. Secret Cow Code
The operation is appending a cyclicly shifted copy of the string onto itself, so if we know the position of the character in the current iteration of the string, then we can trace it back to the character that mapped to it in the previous iteration of the string. Repeat until the string is the original string, and thus we have the original character. The time complexity is $O(logN)$.