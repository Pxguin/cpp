file = open("blink.in","r")
data = file.read().strip().split("\n")
file.close()

n,b = list(map(int,data[0].split(" ")))
lights = [bool(int(data[i+1])) for i in range(n)]

cycled = [list(lights)]
time = 0
cycle = False

for i in range(b):
    prev_state = cycled[time]
    for j in range(n-1):
        if prev_state[j]:
            lights[j+1] = not lights[j+1]
            
    if prev_state[n-1]:
        lights[0] = not lights[0]

    if lights in cycled:
        cycle = True
        time += 1
        break
    else:
        cycled.append(list(lights))
    time += 1

if cycle:
    cycle_start = cycled.index(lights)
    extra = (b-cycle_start)%(time-cycle_start)
    result = cycled[extra+cycle_start]
    final = list(map(int,result))
else:
    final = list(map(int,cycled[time]))

file = open("blink.out","w")
for light in final:
    file.write(str(light)+"\n")
file.close()