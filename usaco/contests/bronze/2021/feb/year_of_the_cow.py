animals = ["Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig","Rat"]
cows = {"Bessie":",Ox,"}

cowNumbers = input()
statements = []

for i in range(int(cowNumbers)):
    statements.append(input())

for statement in statements:
    splitS = statement.split(" ")
    cows[splitS[0]] = splitS[3]+","+splitS[4]+","+splitS[7]

totalYears = 0
currentCow = "Elsie"

path = ["Elsie"]

while not currentCow == "Bessie":
    newCow = cows[currentCow].split(",")[2]
    path.insert(0, newCow)

    currentCow = newCow

path = path[1:]

for cow in path:
    statement = cows[cow].split(",")
    dependency = cows[statement[2]].split(",")

    indexS = animals.index(statement[1])
    indexD = animals.index(dependency[1])

    if statement[0] == "previous":
        if indexS < indexD:
            totalYears += indexD - indexS
        else:
            totalYears += indexD + (12 - indexS)
            
    else:
        if indexS > indexD:
            totalYears -= indexS - indexD
        else:
            totalYears -= (12 - indexD) + indexS

print(abs(totalYears))