from itertools import permutations

#cowOrders = list(permutations(["Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"]))
cowOrders = list(permutations(["Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"]))

file = open("lineup.in", "r")
data = file.read().strip().split("\n")
file.close()

rules = []

for rule in data[1:]:
    rules.append([rule.split()[0],rule.split()[5]])

flag = False

#print(rules)

for lineup in cowOrders:
    flag = True
    
    for rule in rules:   
        cowIndex = lineup.index(rule[1])

        #if lineup == ("Beatrice","Sue","Belinda","Bessie","Betsy","Blue","Bella","Buttercup"):
            #print(cowIndex)

        #print(cowIndex)
            
        if not ((cowIndex > 0 and lineup[cowIndex-1] == rule[0]) or (cowIndex < 7 and lineup[cowIndex+1] == rule[0])):
            flag = False
            break

    if flag:
        file = open("lineup.out", "w")
        for cow in lineup:
            file.write(cow + "\n")
        file.close()
        break