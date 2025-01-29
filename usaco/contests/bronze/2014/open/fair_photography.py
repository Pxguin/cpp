f = open("fairphoto.in","r")
a = f.read().strip().split("\n")
f.close()

n = int(a[0])
cows = []
for i in a[1:]:
    b = i.split(" ")
    cows.append([int(b[0]),0 if b[1] == "H" else 1])
cows.sort()
cows.append([10**9+1,0 if cows[n-1][1] == 1 else 0])

direction = cows[0][1] # G = 1, H = -1
size = 0
start = cows[0][0]
total = 0 # prefix sum
sums = {}
change = False

for j in range(n+1):
    i = cows[j]
    if i[1] != direction:
        direction = i[1]
        size = max(cows[j-1][0]-start,size)
        start = i[0]
    if j != n:
        total += -1 if i[1] == 0 else 1
        if total in sums.keys():
            sums[total][1] = i[0]
        else:
            sums[total] = [cows[j+1][0],0]
for i in sums.values():
    size = max(size,i[1]-i[0])

f = open("fairphoto.out","w")
f.write(str(size))
f.close()