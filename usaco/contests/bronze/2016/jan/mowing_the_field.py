file = open("mowing.in","r")
data = file.read().strip().split("\n")
file.close()

field = [[-1 for i in range(2001)] for i in range(2001)]
fj_x = 1000
fj_y = 1000
time = 0
field[fj_x][fj_y] = 0

x = 100**4

for i in range(int(data[0])):
    move = data[i+1].split(" ")
    direction = (-1,0) if move[0] == "W" else (1,0) if move[0] == "E" else (0,1) if move[0] == "N" else (0,-1)

    for j in range(int(move[1])):
        fj_x += direction[0]
        fj_y += direction[1]
        time += 1

        if field[fj_x][fj_y] != -1:
            x = min(x,time-field[fj_x][fj_y])
        print(time,field[fj_x][fj_y])
        field[fj_x][fj_y] = time
if x == 100**4:
    x = -1
file = open("mowing.out","w")
file.write(str(x))
file.close()