fpointer = open("inputs.txt", "r")
coins = [0]
lines = fpointer.read().replace(" ","").split("\n")
fpointer.close()

for line in lines:
    coins = [0]
    
    for i in line.split(",")[2:]:
        coins.append(int(i))
    
    coins.sort()
    
    moves = [0,0,0,0,0]
    
    for i in range(len(coins)-1):
        for j in range(coins[i+1] - coins[i] - 1):
            moves[j] += 1

            if j == 4:
                break
    
    for i in moves:
        print(i, end=",")
    print("\n")