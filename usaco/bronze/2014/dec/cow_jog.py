file = open("cowjog.in", "r")
data = file.read().strip().split("\n")[1:]
file.close()

data.sort(key = lambda x: int(x.split(" ")[0]), reverse = True)
speed = int(data[0].split(" ")[1])
groups = 1

#print(data)


for cow in data[1:]:
    if int(cow.split(" ")[1]) <= speed:
        groups += 1
        speed = int(cow.split(" ")[1])

file = open("cowjog.out", "w")
file.write(str(groups))
file.close()