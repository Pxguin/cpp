file = open("reduce.in", "r")
data = file.read().strip().split("\n")
file.close()
n = int(data[0])
cows = []
for i in data[1:]:
    cows.append(list(map(int,i.split(" "))))
x = sorted(cows,key=lambda x:x[0])
y = sorted(cows,key=lambda y:y[1])
temp_x = list(x)
temp_y = list(y)
direction = 0
min_area = 2500000000
max_reduce = -1
reduce = [x[0],x[-1],y[0],y[-1]]
for i in range(4): # try removing the min & max from each side to reduce the area of the remaining farm
    temp_x.remove(reduce[i])
    temp_y.remove(reduce[i]) 
    min_area = min(min_area,(temp_x[-1][0]-temp_x[0][0])*(temp_y[-1][1]-temp_y[0][1]))
    # calculate the area of the remaining farm and store the minimum area
    temp_x,temp_y = list(x),list(y)
file = open("reduce.out","w")
file.write(str(min_area))
file.close()