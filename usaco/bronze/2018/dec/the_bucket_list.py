file = open("blist.in", "r")
data = file.read().strip().split("\n")
file.close()

cows = [list(map(int, i.split(" "))) for i in data[1:]]

start = [[i[0],i[2]] for i in cows]
start.sort(key = lambda time : time[0])
start.append([1001,0])

end = [[i[1],i[2]] for i in cows]
end.sort(key = lambda time : time[0])
end.append([1001,0])

buckets = 0
maxBuckets = 0

startLength = len(start)
endLength = len(end)

while startLength > 1 or endLength > 1:
    print(start[0][0], end[0][0])
    if start[0][0] < end[0][0]:
        buckets += start[0][1]
        start.pop(0)
        startLength -= 1
    else:
        buckets -= end[0][1]
        end.pop(0)
        endLength -= 1

    maxBuckets = max(buckets, maxBuckets)

#print(startLength, endLength)

file = open("blist.out", "w")
file.write(str(maxBuckets))
file.close()
