file = open("notlast.in", "r")
data = file.read().strip().split("\n")
file.close()

m = int(data[0])
cows = {"Bessie":0,"Elsie":0,"Daisy":0,"Gertie":0,"Annabelle":0,"Maggie":0,"Henrietta":0}
for i in data[1:]:
    log = i.split(" ")
    cows[log[0]] += int(log[1])

min1 = min(cows.values())
for cow in cows:
    if cows[cow] == min1:
        cows[cow] = 10001

min2 = min(cows.values())
minCows = []

for cow in cows:
    if cows[cow] == min2:
        minCows.append(cow)

file = open("notlast.out", "w")
file.write(minCows[0] if len(minCows) == 1 else "Tie")
file.close()