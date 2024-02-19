file = open("milktemp.in","r")
data = file.read().strip().split("\n")
file.close()
n,x,y,z = list(map(int,data[0].split(" ")))

start = []
end = []
total = {}
milk = n*x
maximum = milk

start_p = 0
end_p = 0

for cow in data[1:]:
    total = list(map(int,cow.split(" ")))
    start.append(total[0])
    end.append(total[1]+1)

start.sort()
end.sort()

while start_p < n and end_p < n:
    if start_p < n:
        if start[start_p] < end[end_p]:
            cow = "s"
            start_p += 1
        else:
            cow = "e"
            end_p += 1
    else:
        cow = "e"
        end_p += 1

    if cow == "s":
        milk += y-x
    else:
        milk -= y-z

    #print(cow)
    maximum = max(milk,maximum)

file = open("milktemp.out","w")
file.write(str(maximum))
file.close()