from math import floor

file = open("pails.in", "r")
data = list(map(int, file.read().split(" ")))
x,y,m = data

maxTimes = floor(m/x)
maxTimesY = floor(m/y)

timesX = maxTimes
timesY = 0

maxMilk = 0
tempMilk = 0

breakLoop = False

while not timesX == -1:
    milkX = timesX * x
    
    for i in range(maxTimesY+1):
        tempMilk = milkX + i * y

        if tempMilk > maxMilk:
            if tempMilk <= m:
                maxMilk = tempMilk
    
                if maxMilk == 1000:
                    breakLoop = True
                    break
            else:
                break
    
    timesX -= 1

    if breakLoop:
        break

file = open("pails.out", "w")
file.write(str(maxMilk))
file.close()