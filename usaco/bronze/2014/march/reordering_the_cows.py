file = open("reorder.in", "r")
data = list(map(int, file.read().strip().split("\n")))
file.close()

n = data[0]
start = data[1:n+1]
end = data[n+1:]

visited = []
shifts = 0
longestShift = -1
goal = 0
chainLength = 0

for cow in start:
    if cow not in visited:
        goal = start.index(cow)
        currentCow = cow
        cowIndex = 0
        chainLength = 0

        while 1:
            cowIndex = end.index(currentCow)
            currentCow = start[cowIndex]
            
            chainLength += 1
            
            visited.append(currentCow)

            if cowIndex == goal:
                break

        if chainLength == 1:
            chainLength = -2
        else:
            shifts += 1

        longestShift = max(longestShift, chainLength)

file = open("reorder.out", "w")
file.write(str(shifts) + " " + str(longestShift))
file.close()