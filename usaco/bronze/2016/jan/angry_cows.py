file = open("angry.in", "r")
data = list(map(int, file.read().strip().split("\n")))
file.close()

bales = data[1:]
bales.sort()

maxExploded = 0

for i in range(data[0]):
    bale = bales[i]
    counter = 0
    current = [bale, bale]
    tempExploded = 1

    failedLeft = False
    failedRight = False

    while (not failedLeft) or (not failedRight):
        counter += 1

        currentLeft = [current[0]]
        currentRight = [current[1]]

        left = current[0] - counter
        right = current[1] + counter

        oldExploded = tempExploded
        if not failedLeft:
            for bale2 in bales[:bales.index(current[0])]:
                if bale2 >= left:
                    tempExploded += 1
                    currentLeft.append(bale2)
    
            if oldExploded == tempExploded:
                failedLeft = True

        oldExploded = tempExploded
        if not failedRight:
            for bale2 in bales[bales.index(current[1])+1:]:
                if bale2 <= right:
                    tempExploded += 1
                    currentRight.append(bale2)

            if oldExploded == tempExploded:
                failedRight = True

        current = [min(currentLeft), max(currentRight)]

    maxExploded = max(maxExploded, tempExploded)

file = open("angry.out", "w")
file.write(str(maxExploded))
file.close()