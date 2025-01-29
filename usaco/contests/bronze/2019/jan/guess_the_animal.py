from itertools import combinations

file = open("guess.in", "r")
data = file.read().strip().split("\n")
file.close()

n = int(data[0])
animals = {}

for i in data[1:]:
    animal = i.split(" ")

    animals[animal[0]] = [detail for detail in animal[2:]]

pairs = list(combinations(animals, 2))

maxShared = 0

for pair in pairs:
    shared = 0
    
    a1,a2 = pair

    d1,d2 = animals[a1],animals[a2]

    if len(d2) > len(d1):
        d1,d2 = d2,d1

    for detail in d1:
        if detail in d2:
            shared += 1

    if shared > maxShared:
        maxShared = shared

file = open("guess.out", "w")
file.write(str(maxShared + 1))
file.close()