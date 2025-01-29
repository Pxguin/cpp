file = open("mixmilk.in", "r")
data = file.read().strip().split("\n")
file.close()

bucket1 = list(map(int, data[0].split(" ")))
bucket2 = list(map(int, data[1].split(" ")))
bucket3 = list(map(int, data[2].split(" ")))

for i in range(100):
    if i%3 == 0:
        difference = bucket2[0] - bucket2[1]
        if difference > bucket1[1]:
            bucket2[1] += bucket1[1]
            bucket1[1] = 0
        else:
            bucket2[1] += difference
            bucket1[1] -= difference
            
    elif i%3 == 1:
        difference = bucket3[0] - bucket3[1]
        if difference > bucket2[1]:
            bucket3[1] += bucket2[1]
            bucket2[1] = 0
        else:
            bucket3[1] += difference
            bucket2[1] -= difference

    elif i%3 == 2:
        difference = bucket1[0] - bucket1[1]
        if difference > bucket3[1]:
            bucket1[1] += bucket3[1]
            bucket3[1] = 0
        else:
            bucket1[1] += difference
            bucket3[1] -= difference


file = open("mixmilk.out", "w")
file.write(str(bucket1[1]) + "\n" + str(bucket2[1]) + "\n" + str(bucket3[1]))
file.close()