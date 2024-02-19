rectangleInput = input("Enter a data set: ")

rows = int(rectangleInput[0])
rectangles = []

for i in range(rows):
    rectangles.append([])

maxSum = 0
currentSum = 0
toAdd = []


for iter, num in enumerate(rectangleInput.split(" ")[2:]):
    rectangles[iter//3].append(int(num))

for rowNo, aRow in enumerate(rectangles):
    for columnNo, tile in enumerate(aRow):
        for i in range(columnNo, len(rectangles[0])):
            for j in range(rowNo, len(rectangles)):
                for k in rectangles[rowNo:j+1]:
                    for l in k[columnNo:i+1]:
                        currentSum += l
                if currentSum > maxSum:
                    maxSum = currentSum
                currentSum = 0
print(maxSum)