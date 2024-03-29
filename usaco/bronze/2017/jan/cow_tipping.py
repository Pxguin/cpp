file = open("cowtip.in", "r")
data = file.read().strip().split("\n")
file.close()

n = int(data[0])
farm = []
for row in data[1:]:
    farm.insert(0,list(map(int,reversed([i for i in row]))))

flips = 0

def flip(pos):
    for i in farm[pos[0]:]:
        for j in range(pos[1], n):
            i[j] = int(not i[j])

for i in range(n):
    corner = farm[i][i]

    if corner == 1:
        flips += 1
        flip((i,i))

    
    for j in range(i, n):
        if farm[i][j] == 1:
            flip((i,j))
            flips += 1

    for j in range(i, n):
        if farm[j][i] == 1:
            flip((j,i))
            flips += 1
            
file = open("cowtip.out", "w")
file.write(str(flips))
file.close()