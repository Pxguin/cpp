file = open("swap.in","r")
data = file.read().strip().split("\n")
file.close()
n,k = list(map(int,data[0].split(" ")))
s_1 = tuple(map(int,data[1].split(" ")))
s_2 = tuple(map(int,data[2].split(" ")))

affect = (min(s_1+s_2)-1,max(s_1+s_2))
cows = [i+1 for i in range(n)][affect[0]:affect[1]]
s_1 = (s_1[0]-affect[0]-1,s_1[1]-affect[0])
s_2 = (s_2[0]-affect[0]-1,s_2[1]-affect[0])
swaps = [s_1,s_2] # makes sure that only the area being swapped is being stored in the list of previous occurences to reduce runtime

cycled = [list(cows+[1])]
swap = 1
current = 0

cycle = False

for i in range(k*2):
    current += 1
    swap = int(not swap)
    cows[swaps[swap][0]:swaps[swap][1]] = reversed(cows[swaps[swap][0]:swaps[swap][1]])

    if cows+[swap] in cycled and cycled[current-1][-1] == int(not swap): # make sure that a cycle exists (one may not exist if the start & end of the cycle are on the same swap instead of different ones)
        cycle = True
        break
    else:
        cycled.append(list(cows+[swap]))

if cycle: # calculate the remainder and find the answer
    cycle_start = cycled.index(cows+[swap])
    extra = (k*2-cycle_start)%(current-cycle_start)
    result = cycled[extra+cycle_start][:-1]
else:
    result = cycled[current][:-1]

start = [i+1 for i in range(n)]
file = open("swap.out","w")
for cow in start[:affect[0]]+result+start[affect[1]:]:
    file.write(str(cow)+"\n")
file.close()