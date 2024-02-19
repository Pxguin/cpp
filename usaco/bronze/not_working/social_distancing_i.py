file = open("socdist1.in","r")
n,cows = file.read().strip().split("\n")
file.close()
n = int(n)
cows = [1]+list(map(int,list(cows)))+[1]

distances = []
min_dist = 10**6
distance_start = 0
pointer = 1

ends = [0,0]

while pointer != n+2:
    if cows[pointer] == 0:
        distance_start = pointer
        while cows[pointer] != 1:
            pointer += 1
            if cows[pointer] == 1:
                if distance_start == 1:
                    ends[0] = pointer-distance_start
                elif pointer == n+1:
                    ends[1] = pointer-distance_start
                else:
                    distances.append(pointer-distance_start)
                    if pointer-distance_start < min_dist:
                        min_dist = pointer-distance_start
    pointer += 1

if len(distances) == 0:
    pass
else:
    for i in range(2):
        distances.sort(reverse=True)
        ends.sort(reverse=True)
        
        if (distances[0]-1)//2 >= min_dist:
            distances.append(distances[0] - (distances[0]-1)//2)
            distances[0] = (distances[0]-1)//2
            if (distances[0]-2)//3 >= min_dist:
                break
        else:
            if min_dist+1 <= ends[0]:
                distances.append(min_dist)
                ends[0] -= min_dist+1
            else:
                if (distances[0]-1)//2 > ends[0]-1:
                    distances.append(distances[0] - (distances[0]-1)//2)
                    distances[0] = (distances[0]-1)//2
                    min_dist = distances[0]
                else:
                    distances.append(ends[0]-1)
                    ends[0] = 0
                    min_dist = distances[-1]

file = open("socdist1.out","w")
file.write(str(min_dist+1))
file.close()