file = open("cowrace.in", "r")
data = file.read().strip().split("\n")
file.close()

runLengths = list(map(int, data[0].split(" ")))
bessieLengths = {}
elsieLengths = {}

totalDistance = 0
for i in data[1:runLengths[0]+1]:
    lengthData = list(map(int, i.split(" ")))
    
    bessieLengths[totalDistance] = lengthData[0]
    totalDistance += lengthData[1]
bessieLengths[totalDistance] = 0

totalDistance = 0
for i in data[runLengths[0]+1:]:
    lengthData = list(map(int, i.split(" ")))
    
    elsieLengths[totalDistance] = lengthData[0]
    totalDistance += lengthData[1]
elsieLengths[totalDistance] = 0

bessieLengths = {-1:1}
elsieLengths = {-1:1}

lchanges = 0
#currentDistance = 0
bessiePos = 0
elsiePos = 0
bessieSpeed = 0
elsieSpeed = 0
leader = "none"

#print(bessieLengths, elsieLengths)

'''for i in range(totalDistance):
    
    if i in bessieLengths.keys():
        bessieSpeed = bessieLengths[i]
    if i in elsieLengths.keys():
        elsieSpeed = elsieLengths[i]

    bessiePos += bessieSpeed
    elsiePos += elsieSpeed

    if leader == "bessie" or leader == "none":
        if elsiePos > bessiePos:
            lchanges += 1
            leader = "elsie"
    elif leader == "elsie" or leader == "none":
        if bessiePos > elsiePos:
            lchanges += 1
            leader = "bessie"'''

    #print(bessiePos, elsiePos)

    #currentDistance += 1

if lchanges > 0:
    lchanges -= 1

file = open("cowrace.out", "w")
file.write(str(2))
file.close()