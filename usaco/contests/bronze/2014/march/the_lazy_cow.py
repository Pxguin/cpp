file = open("lazy.in","r")
a = file.read().strip().split("\n")
x = []
g = []
n,k = list(map(int,a[0].split(" ")))
k *= 2
l = []
for i in a[1:]:
    l.append(list(reversed(list(map(int,i.split(" "))))))
l.sort()
for j in l:
    x.append(j[0])
    g.append(j[1])

max_grass = 0
temp = g[0]
end = x[0]+k
end2 = 0
for i in range(1,n):
    if x[i] <= x[0]+k:
        temp += g[i]
        end2 = i
    else:
        break
max_grass = temp

for i in range(1,n):
    temp -= g[i-1]
    moved = x[i] - x[i-1]
    for j in range(end2+1,n):
        if x[j] <= end+moved:
            temp += g[j]
            end2 = j
        else:
            break
    end = x[i]+k
    max_grass = max(max_grass,temp)

file = open("lazy.out","w")
file.write(str(max_grass))
file.close()