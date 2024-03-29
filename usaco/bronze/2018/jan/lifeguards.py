file = open("lifeguards.in", "r")
data = file.read().strip().split("\n")

for i in range(int(data[0])):
    data[i+1] = list(map(int, data[i+1].split(" ")))

file.close()
pool = [0 for i in range(1001)]

for shift in data[1:]:
    for i in range(shift[0],shift[1]):
        pool[i] += 1

maxTime = 0
currentTime = 0
for shift in data[1:]:
    for i in range(shift[0],shift[1]):
        pool[i] -= 1

    for i in pool:
        if i > 0:
            currentTime += 1

    for i in range(shift[0],shift[1]):
        pool[i] += 1

    #print(currentTime,shift)

    
    maxTime = max(maxTime, currentTime)
    currentTime = 0

file = open("lifeguards.out", "w")
file.write(str(maxTime))
file.close()