n = int(input())
start = list(map(int,input().split(" ")))
end = list(map(int,input().split(" ")))

cows = {}

for i in range(n):
    cows[end[i]] = i+1

maximum = 0
moves = 0
for i in range(1,n):
    maximum = max(cows[start[i-1]],maximum)
    if cows[start[i]] < maximum:#cows[start[i-1]]:
        moves += 1

print(moves)