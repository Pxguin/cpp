file = open("lostcow.in", "r")
x,y = list(map(int, file.read().strip().split(" ")))
file.close()

move = 1
pos = x
distance = 0

if x < y:
    while pos < y:
        distance += abs(pos-x)+abs(move)
        pos += move + (x-pos)
        move *= -2
    distance -= pos-y

elif x > y:
    while pos > y:
        #print(abs(pos-x)+abs(move), pos, x, move)
        distance += abs(pos-x)+abs(move)
        pos += move + (x-pos)
        move *= -2
    distance -= y-pos

file = open("lostcow.out", "w")
file.write(str(distance))
file.close()