file = open("hps.in", "r")
data = file.read().strip().split("\n")
n = int(data[0])
games = [list(map(int, i.split(" "))) for i in data[1:]]

from itertools import permutations

gestures = list(permutations([1,2,3]))

wins = 0
maxWins = 0

for combination in gestures:
    wins = 0
    
    for game in games:
        cow1 = combination[game[0]-1]
        cow2 = combination[game[1]-1]
        
        if (cow1 == 1 and cow2 == 2) or (cow1 == 2 and cow2 == 3) or (cow1 == 3 and cow2 == 1):
            wins += 1

    if wins == 3:
        print(combination)

    maxWins = max(wins, maxWins)

file = open("hps.out", "w")
file.write(str(maxWins))
file.close()