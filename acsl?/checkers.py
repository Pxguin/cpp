checkers = input()

enemies = []

paths = []

# Use inputs without spaces between numbers like 3,4 instead of 3, 4

split = checkers.split(",")

paths.append([[int(split[0]),int(split[1])]])

jumps = []

for i in range(3,len(split)-1,2):
    enemies.append([int(split[i]),int(split[i+1])])

breakLoop = False

while not breakLoop:
    for i in paths:    

        jump1R = [i[-1][0]+1,i[-1][1]+1]
        jump2R = [i[-1][0]+2,i[-1][1]+2]

        jump1L = [i[-1][0]+1,i[-1][1]-1]
        jump2L = [i[-1][0]+2,i[-1][1]-2]

        if jump2R[1] <= 8 and jump2R[0] <= 8 and jump1R in enemies and jump2R not in enemies:
            
            if jump2L[1] > 0 and jump2L[0] <= 8 and jump1L in enemies and jump2L not in enemies:
                paths.append(list(i).append(jump2R))
                i.append(jump2L)

            else:
                i.append(jump2R)

        elif jump2L[1] > 0 and jump2L[0] <= 8 and jump1L in enemies and jump2L not in enemies:
            i.append(jump2L)
        else:
            if len(paths) <= 1:
                breakLoop = True
                break
            paths.remove(i)


for i in paths:
    if i[-1][0] == 8:
        print(str(len(i)-1) + ", KING")
    else:
        print(len(i)-1)
            