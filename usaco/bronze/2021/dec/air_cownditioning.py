n = int(input(""))
goal = list(map(int, input("").split(" ")))
current = list(map(int, input("").split(" ")))

goal.append(0)
current.append(0)
    
for i in range(n):
    current[i] = goal[i] - current[i]

chain = False
sign = 0
changes = 0

cowChain = []

for i in range(n+1):
    cow = current[i]

    if chain:
        if cow != 0 and cow/abs(cow) == sign:
            cowChain.append(cow)
        else:
            cowChain.append(0)
            chain = False
            chainLen = len(cowChain)
            start = 0
            minCow = 10001
            while start != chainLen:
                for j in range(start,chainLen):
                    if cowChain[j] == 0:
                        for k in range(j):
                            cowChain[k] += -1*sign*minCow
                        changes += minCow
                        break
                    else:
                        minCow = min(minCow,abs(cowChain[j]))
        
                for j in range(start,chainLen):
                    if cowChain[j] != 0:
                        start = j
                        break
                    else:
                        start += 1

    if not chain:
        if cow != 0:
            sign = cow/abs(cow)
            chain = True
            cowChain = [cow]

print(int(changes))