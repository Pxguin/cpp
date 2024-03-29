file = open("factory.in","r")
data = file.read().strip().split("\n")
n = int(data[0])

stations = [0 for i in range(n)]

for i in range(n-1):
    start,end = list(map(int,data[i+1].split(" ")))
    stations[start-1] += 1

station_i = []

for i in range(n):
    station = stations[i]
    if station == 0:
        station_i.append(i)

file = open("factory.out","w")
file.write(str(station_i[0]+1 if len(station_i) == 1 else -1))
file.close()