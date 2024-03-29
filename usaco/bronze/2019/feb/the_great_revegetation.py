file = open("revegetate.in","r")
data = file.read().strip().split("\n")
file.close()

n,m = map(int,data[0].split(" "))

pastures = [0 for i in range(n)]
graph = [[] for i in range(n)]

for i in range(m):
    p1,p2 = list(map(int,data[i+1].split(" ")))
    graph[p1-1].append(p2-1)
    graph[p2-1].append(p1-1)

for i in range(n):
    taken = [1,2,3,4]
    connected = graph[i]
    
    for pasture in connected:
        if pastures[pasture] != 0:
            taken[pastures[pasture]-1] = 0

    for seed in taken:
        if seed != 0:
            pastures[i] = seed
            break

file = open("revegetate.out","w")
for seed in pastures:
    file.write(str(seed if seed != 0 else 1))
file.close()