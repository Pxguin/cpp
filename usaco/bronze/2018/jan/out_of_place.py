file = open("outofplace.in","r")
data = file.read().strip().split("\n")
file.close()

n = int(data[0])
cows = list(map(int,data[1:]))
cows.insert(0,0)
cows.append(1000001)

direction = -1
cow_index = 0

for i in range(n):
    if cows[i+1] > cows[i+2] and cows[i+2] >= cows[i]:
        direction = 1
        cow_index = i+1
        break
    elif cows[i+1] < cows[i]:
        direction = 0
        cow_index = i+1
        break

swap = []
swaps = 0

if direction == 1:
    for i in range(cow_index+1,n+2):
        if cows[cow_index] > cows[i]:
            swap.append(cows[i])
        else:
            swaps = len(set(swap))
            break
elif direction == 0:
    for i in range(cow_index-1,-1,-1):
        if cows[cow_index] < cows[i]:
            swap.append(cows[i])
        else:
            swaps = len(set(swap))
            break

file = open("outofplace.out","w")
file.write(str(swaps))
file.close()