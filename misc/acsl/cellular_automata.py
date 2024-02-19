import copy

file = open("cells.txt", "r")
inputs = file.read().replace(" ","").split("\n")
file.close()

for input1 in inputs:
    newInput = input1.split(",")
    cells = newInput[1:-1]
    cells.insert(0,"D")
    cells.append("D")
    cellNo = int(newInput[0])
    
    for i in range(int(newInput[-1])):
        cellCopy = copy.deepcopy(cells)
        for j in range(cellNo):
            cell = j+1
                
            if cells[cell-1] == "A":
                if cells[cell+1] == "A":
                    cellCopy[cell] = "D"
                else:
                    cellCopy[cell] = "A"
    
            elif cells[cell+1] == "A":
                if cells[cell-1] == "A":
                    cellCopy[cell] = "D"
                else:
                    cellCopy[cell] = "A"
            else:
                cellCopy[cell] = "D"
    
        cells = copy.deepcopy(cellCopy)
    

    for i in cells[1:-1]:
        print(i, end="")
    print("\n")