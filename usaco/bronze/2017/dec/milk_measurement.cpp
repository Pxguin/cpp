file = open("measurement.in", "r")
data = file.read().strip().split("\n")[1:]
data.sort(key=lambda x: int(x.split(" ")[0]))
file.close()

changes = 0

cows = {"Bessie":7,"Elsie":7,"Mildred":7}

leader = []

for i in data:
    change = i.split(" ")[1:]
    cows[change[0]] += int(change[1])

    change = False
    
    for j in cows.keys():
        if cows[j] == max(cows.values()):
            if j not in leader:
                leader.append(j)
                change = True
        elif j in leader:
            leader.remove(j)
            change = True

    if change:
        changes += 1
            
file = open("measurement.out", "w")
file.write(str(changes))
file.close()