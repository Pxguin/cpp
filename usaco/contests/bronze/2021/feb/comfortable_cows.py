cowNumber = int(input())
cows = [[0 for i in range(1001)] for j in range(1001)]

comfyCows = 0

for i in range(cowNumber):

    x,y = map(int, input().split(" "))

    cows[x][y] = 1

    dx = [1,-1,0,0]
    dy = [0,0,1,-1]

    check = [[x,y],[x+1,y],[x-1,y],[x,y+1],[x,y-1]]
    
    for cow in check:
        neighbors = 0
        for j in range(4):

            xpos = cow[0]+dx[j]
            ypos = cow[1]+dy[j]
            
            if -1 < xpos < 1001 and -1 < ypos < 1001 and cows[cow[0]][cow[1]] == 1 and cows[xpos][ypos] == 1:
                neighbors += 1
    
        if neighbors == 4:
            comfyCows -= 1
        elif neighbors == 3:
            comfyCows += 1

    print(comfyCows)