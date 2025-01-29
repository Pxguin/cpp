file = open("cowqueue.in","r")
data = file.read().strip().split("\n")
file.close()
n = int(data[0])
start = []
end = []
cows = [list(map(int,i.split(" "))) for i in data[1:]]
cows.sort()
for cow in cows:
    start.append(cow[0])
    end.append(cow[1])
end[0] = start[0]+end[0]
for i in range(1,n):
    time = start[i]
    end[i] = start[i]+end[i]
    if time <= end[i-1]:
        difference = end[i-1]-time
        start[i] += difference
        end[i] += difference
file = open("cowqueue.out","w")
file.write(str(end[n-1]))
file.close()