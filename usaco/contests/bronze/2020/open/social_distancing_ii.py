file = open("socdist2.in","r")
file_input = file.read().strip().split("\n")
file.close()

n = int(file_input[0])
cows = [list(map(int,i.split(" "))) for i in file_input[1:]]
cows.sort()
cows.append([10**7,0])

max_r = 10**8
pointer = 0
flag = False
min_infected = 0

all_infected = True

for i in range(len(cows)):
    if cows[i][1] == 0:
        all_infected = False
        if i != 0:
            max_r = min(cows[i][0]-cows[i-1][0] if cows[i-1][1] == 1 else max_r,max_r)
        if i != len(cows)-1:
            max_r = min(cows[i+1][0]-cows[i][0] if cows[i+1][1] == 1 else max_r,max_r)
max_r -= 1

if all_infected == False:
    while pointer != len(cows):
        if cows[pointer][1] == 1:
            last_infected = cows[pointer][0]
            while 1:
                pointer += 1
                if cows[pointer][0]-last_infected <= max_r:
                    last_infected = cows[pointer][0]
                else:
                    min_infected += 1
                    pointer -= 1
                    break
                    
        pointer += 1
else:
    min_infected = 1

file = open("socdist2.out","w")
file.write(str(min_infected))
file.close()