file = open("badmilk.in","r")
a = file.read().strip().split("\n")
file.close()
n,m,d,s = list(map(int,a[0].split(" ")))

events = {}

for i in range(m):
    events[i+1] = []

for i in a[1:d+1]:
    j = list(map(int,i.split(" ")))
    events[j[1]].append([j[0],j[2]])

sick = []
for i in a[d+1:]:
    j = list(map(int,i.split(" ")))
    sick.append([j[0],j[1]])
    
doses = 0

for i in range(1,m+1):
    is_sick = 0
    for j in sick:
        for k in events[i]:
            if k[0] == j[0] and k[1] < j[1]:
                is_sick += 1
                break
                
    if is_sick == s:
        unique = []
        for j in events[i]:
            if j[0] not in unique:
                unique.append(j[0])
        doses = max(len(unique),doses)

file = open("badmilk.out","w")
file.write(str(doses))
file.close()
                