file = open("odometer.in", "r")
x,y = file.read().strip().split(" ")
file.close()

x2,y2 = int(x)-1, int(y)+1

moos = 0

for i in range(len(y)-len(x)+1):
    length = len(x)+i
    
    for j in range(length):
        
        for uniqueNumber in range(10):
            for sameNumber in range(10):
                if sameNumber != uniqueNumber:
                    genNumber = [str(sameNumber) for i in range(length)]
                    genNumber[j] = str(uniqueNumber)
                    genNumber = "".join(genNumber)
                    genInt = int(genNumber)
                    
                    if genNumber[0] != "0" and genInt < y2 and genInt > x2:
                        moos += 1
file = open("odometer.out", "w")
file.write(str(moos))
file.close()