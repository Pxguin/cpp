# USACO Silver 2019 US Open

## 1 - Left Out

The official solution is much more unique (but constructive); here I'll present my solution which is rooted more in logical steps.

For simplicity we will replace all L's with 0's and R's with 1's. Then we have a grid of 0 and 1.

We can first start with a grid consisting of all 0's or 1's. Then notice that no matter how you flip rows and columns, in the end all rows and columns will have the same 01 pattern (inverted or not). This makes logical sense; when you invert a row nothing happens to the 01 pattern, and when you invert a column all the rows are inverted at the same position. This also means that we only have to check the rows: if they all have the same pattern, then all the columns must too. With this, we create a binary string for each row and store the frequency of each string in a map. To deal with the possibility of an inverted pattern, we will invert the string as necessary to make sure the first element is always a 0.

To have a single flipped cow at the very end means that exactly one of the row patterns is different from all the others by one bit. Obviously, if all rows have the same pattern or there are more than 2 different patterns, it is false. Otherwise, let's go through all rows. If the frequency of its pattern is 1, then let's see if it differs from the other bit string (there must only be 2 unique ones) by one bit.

This is easy to do: go through every bit, try inverting it, and see if the resulting pattern is the second pattern. If it is we just take the earliest column index such that we can do this. Also, because the final grid can be all 0's or 1's, we need to repeat this proccess, but with this pattern inverted.

In my code I have an $O(N^3)$ loop (due to comparing strings), but the inner loop will at most run one time so the total complexity is $O(N^2)$ (solution is messy, btw). 

As a matter of fact you could easily remove the outer loop by the note that there are only two bit strings to compare, so you pre-find the string with frequency 1 while processing the input data. The special case where $N=2$ (so both strings have frequency 1) is of no concern because either string can be inverted into the other so the solution will always be in the first row.