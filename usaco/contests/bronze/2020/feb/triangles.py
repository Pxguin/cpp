file = open("triangles.in", "r")
data = file.read().strip().split("\n")
file.close()

n = int(data[0])

triangles = [list(map(int, i.split(" "))) for i in data[1:]]


maxArea = 0
side1 = 0
side2 = 0

for point1 in range(n):
    tri1 = triangles[point1]
    
    for point2 in range(n-point1-1):
        tri2 = triangles[point2+point1+1]

        for point3 in range(n-point2-point1-2):
            tri3 = triangles[point3+point2+point1+2]
            #print(tri1,tri2,tri3)
            
            for points in [[tri1, tri2],[tri1,tri3],[tri2,tri3]]:
                if points[0][0] == points[1][0]:
                    side1 = abs(points[0][1]-points[1][1])
                    break
                    
            for points in [[tri1, tri2],[tri1,tri3],[tri2,tri3]]:
                if points[0][1] == points[1][1]:
                    side2 = abs(points[0][0]-points[1][0])
                    break

            maxArea = max(side1*side2, maxArea)
            side1,side2 = 0,0
            currentArea = 0

file = open("triangles.out", "w")
file.write(str(maxArea))
file.close()