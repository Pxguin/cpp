# South African Computing Olympiad 2015 Final Round

## 4. Space Jazz

https://saco-evaluator.org.za/cms/sapo2015z/tasks/jazz/description

This is my first dip into the waters of range DP so my understanding isn't very deep right now. Basically define $dp[i][j]$ as the answer for substring $i...j$. For a given substring, calculate the answer for it by trying to pair up the first letter with a matching character. If you have a matching one then any characters to the left and right of that character can't be paired up with each other, based on the definition of space jazz. So add up the dp values for those two substrings to get a candidate for this substring. Alternatively, you don't have to pair up the first character, in which case you will simply try to duplicate it. Nevertheless, the time complexity is $O(N^3)$... there are some practice problems in USACO guide with $N<=1000$ so I'm unsure about them, but I guess I'll see soon.