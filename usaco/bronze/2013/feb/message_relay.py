file = open("relay.in", "r")
data = list(map(int, file.read().strip().split("\n")))
file.close()

cows = data[1:]
nonLoopy = 0

copy = list(cows)

for i in range(data[0]):
    cow = cows[i]
    
    if cow == 0:
        currentStage = []
        nextStage = []
        stage = 0
        
        copy[i] = "x"
        currentStage = [i]
        first = 1
        
        while stage > 0 or first:
            first = 0
            stage = 0
            
            for j in range(len(copy)):
                if copy[j] != "x":
                    newCow = copy[j]-1
    
                    for goal in currentStage:
                        if newCow == goal:
                            nextStage.append(j)
                            stage += 1
                            copy[j] = "x"
                            print(copy)

            #print(currentStage, nextStage)

            nonLoopy += len(currentStage)
            currentStage = list(nextStage)
            nextStage = []

        nonLoopy += len(currentStage)

file = open("relay.out", "w")
file.write(str(nonLoopy))
file.close()