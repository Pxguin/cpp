n = int(input())
cows = list(map(int, input().split(" ")))
stalls = list(map(int, input().split(" ")))

stalls.append(0)

cows.sort(reverse=True)
stalls.sort(reverse=True)

combinations = 1

for i in range(n):
    cow = cows[i]

    for j in range(n+1):
        if stalls[j] < cow:
            combinations *= j-i
            break
            
print(combinations)