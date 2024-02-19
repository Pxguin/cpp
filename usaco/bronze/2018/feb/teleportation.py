file = open("teleport.in", "r")
data = file.read()
file.close()

a,b,c,d = map(int, data.split(" "))

a,b = min(a,b),max(a,b)

if (abs(c-a) > abs(d-a)):
    c,d = d,c

write = b-a

if c > a and d < b and c < b and d > c: # both on inside
    write -= d-c

if abs(a-c) + abs(b-d) < write: # both to the left
    write = abs(a-c) + abs(b-d)

if abs(c-a) + abs(d-b) < write: # both to the right
    write = abs(c-a) + abs(d-b)

if abs(a-c) + abs(d-b) < write: # both on outside
    write = abs(a-c) + abs(d-b)

file = open("teleport.out", "w")
file.write(str(write))
file.close()