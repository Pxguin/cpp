file = open("milkorder.in","r")
data = file.read().strip().split("\n")
n,m,k = list(map(int,data[0].split(" ")))
order = list(map(int,data[1].split(" ")))

cows = [-1 for i in range(n)]
answer = 0
for i in data[2:]:
    cow = i.split(" ")
    cows[int(cow[1])-1] = int(cow[0])
    if int(cow[0]) == 1:
        answer = int(cow[1])

if 1 in order:
    #print(order)
    pre = order[:order.index(1)+1]
    start_i = cows.index(list(filter(lambda x: x != -1, cows))[0])+1
    #print(pre,cows)
    extra = 1
    for i in reversed(pre):
        if i in cows:
            start_i = cows.index(i)+1
            pre = pre[pre.index(i)+1:]
            extra = len(pre)
            for j in cows[start_i-1:]:
                if pre == [1]:
                    break
                if j == -1:
                    pre.remove(pre[0])
                    extra += 1
            break
    answer = start_i+extra
else:
    last_index = 0
    for i in range(m):
        if order[i] in cows:
            add = order[last_index:i]
            last_index = i+1
            for j in range(cows.index(order[i])-1,-1,-1):
                if not add:
                    break
                else:
                    if cows[j] == -1:
                        cows[j] = add[-1]
                        add.remove(add[-1])
    answer = cows.index(-1)+1
#print(cows)
file = open("milkorder.out","w")
file.write(str(answer))
file.close()

##################################

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