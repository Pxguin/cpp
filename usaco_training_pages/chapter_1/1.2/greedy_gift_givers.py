import math

fin = open("gift1.in", 'r')
fout = open("gift1.out", 'w')

people = []
balance = []
totalPeople = fin.readline()
counter = 0

while counter != int(totalPeople):
    people.append(fin.readline().strip())
    balance.append(0)
    counter += 1

y = 0

while y != int(totalPeople):
    x = fin.readline()
    x = x.strip()
    for name in people:
        boppers = 0
        if x == name:
            xIndex = people.index(x)
            xBalance,numPeople = fin.readline().split()
            if int(numPeople) > 0:
                money = math.floor(int(xBalance) / int(numPeople)) * int(numPeople)

                balance[xIndex] -= money 

                while boppers != int(numPeople):
                    newLine = fin.readline()
                    newLine = newLine.strip()
                    bops = people.index(newLine)
                    balance[bops] += math.floor(int(xBalance) / int(numPeople))
                    boppers += 1
            else:
                continue

    y += 1

for i in people:
    boppy = people.index(i)
    fout.write(i + " " + str(balance[boppy]) + "\n")
fout.close()

totalPeople = totalPeople.strip()