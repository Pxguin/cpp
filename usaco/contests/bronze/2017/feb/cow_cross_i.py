file = open("crossroad.in","r")
data = file.read().strip().split("\n")
file.close()
cows = {}
crosses = 0
n = int(data[0])
for i in range(n):
    log = list(map(int,data[i+1].split(" ")))
    if log[0] in cows.keys():
        if cows[log[0]] != log[1]:
            cows[log[0]] = log[1]
            crosses += 1
    else:
        cows[log[0]] = log[1]
file = open("crossroad.out","w")
file.write(str(crosses))
file.close()