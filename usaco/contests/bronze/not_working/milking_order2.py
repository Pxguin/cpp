file = open("milkorder.in","r")
data = file.read().strip().split("\n")
file.close()

n,m,k = list(map(int,data[0].split(" ")))
cows = [0 for i in range(n)]
hierarchy = list(map(int,data[1].split(" ")))

for i in data[2:]:
    cow = list(map(int,i.split(" ")))
    cows[cow[1]-1] = cow[0]

if 1 in cows:
    answer = cows.index(1)
else:
    for i in range(n):
        if cows[i] == 0:
            flag = False
            copy = list(cows)
            copy[i] = 1
            start = 0
            prev_j = 0
            end = 0
            for j in range(m):
                cow = hierarchy[j]
                if cow in copy:
                    fit = j-prev_j
                    prev_j = j+1
                    available = 0
                    end = copy.index(cow)
                    for cow2 in copy[start:end]:
                        if cow2 == 0:
                            available += 1
                    start = end+1
                    if available < fit:
                        flag = True
                        break
            
            if not flag:
                answer = i
                break

file = open("milkorder.out","w")
file.write(str(answer+1))
file.close()