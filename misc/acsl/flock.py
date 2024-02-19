file = open("flock.txt", "r")
inputs = file.read().replace(" ","").split("\n")
file.close()

for input1 in inputs:
    newInput = input1.split(",")
    birds = newInput[1:-1]

    for i in range(len(birds)):
        birds[i] = int(birds[i])
    
    for i in range(int(newInput[-1])-1):
        if birds[0] != 1 and birds[-1] == 10:
    
            birds.pop(-1)
            birds.insert(0,1)
    
            for j in range(len(birds)-1):
                if birds[j+1]+1 not in birds and birds[j+1]+1 <= 10:
                    birds[j+1] = birds[j+1]+1
    
        else:
            for j in range(len(birds)):
                if birds[j]+1 not in birds and birds[j]+1 <= 10:
                    birds[j] = birds[j]+1
    
    for bird in birds:
        print(bird,end=",")

    print("\n")