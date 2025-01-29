file = open("herding.in","r")
cows = list(map(int,file.read().strip().split(" ")))
file.close()
cows.sort()

minimum = 0
maximum = 0

if (cows[2]-cows[1] == 2) or (cows[1]-cows[0] == 2):
    minimum = 1
elif cows[2]-cows[0] != 2:
    minimum = 2

maximum = max(cows[2]-cows[1],cows[1]-cows[0])-1

file = open("herding.out","w")
file.write(str(minimum)+"\n"+str(maximum))
file.close()