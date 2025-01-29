file = open("cbarn.in", "r")
data = list(map(int, file.read().strip().split("\n")))
file.close()

rooms = data[0]
barn = data[1:]*2
cows = sum(data[1:])
tempCows = cows
#print(cows)
steps = []

for i in range(rooms):
    tempSteps = 0
    for room in barn[i:i+rooms+1]:
        if tempCows > room:
            tempSteps += tempCows - room
            tempCows -= room
        else:
            steps.append(tempSteps)
            break
    tempCows = cows

file = open("cbarn.out", "w")
file.write(str(min(steps)))
file.close()