file = open("breedflip.in", "r")
data = file.read().strip().split("\n")
file.close()

goal = data[1]
current = data[2]
currentIndex = 0
flips = 0
chain = ""

while not currentIndex == len(current):
    if current[currentIndex] == goal[currentIndex]:
        if chain != "":
            chain = ""
            flips += 1
    else:
        chain += current[currentIndex]

    currentIndex += 1

if chain != "":
    flips += 1

file = open("breedflip.out", "w")
file.write(str(flips))
file.close()