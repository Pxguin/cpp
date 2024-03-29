file = open("cownomics.in","r")
i = file.read().strip().split("\n")
file.close()

n,m = list(map(int,i[0].split(" ")))
spots = i[1:n+1]
plain = i[n+1:]

answer = 0
for i in range(m):
    total = []
    spot = []
    for j in range(n):
        total.append(plain[j][i])
        spot.append(spots[j][i])
    total = list(set(total))
    
    flag = False
    for gene in spot:
        if gene in total:
            flag = True
            break
    if not flag:
        answer += 1

file = open("cownomics.out","w")
file.write(str(answer))
file.close()