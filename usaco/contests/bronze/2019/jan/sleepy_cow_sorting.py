file = open("sleepy.in","r")
data = file.read().strip().split("\n")
file.close()

n = int(data[0])
cows = list(map(int,data[1].split(" ")))

moves = 0
for i in range(n-2,-1,-1):
    if cows[i] > cows[i+1]:
        moves = i+1
        break

file = open("sleepy.out","w")
file.write(str(moves))
file.close()