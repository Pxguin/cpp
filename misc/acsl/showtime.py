file = open("clock.txt", "r")
data = file.read().strip().split("\n")
file.close()

clock = ["r","g","b","y","c","m","w","k"]
squareSizes = [1,1,2,3,5]

for text in data:
    hours,minutes,seconds = list(map(int, text.split(":")))
    
    for a in clock:
        for b in clock:
            for c in clock:
                for d in clock:
                    for e in clock:
                        newClock = a+b+c+d+e
    
                        tempHours = 0
                        tempMinutes = 0
                        tempSeconds = 0
    
                        for i in range(5):
                            currentSquare = squareSizes[i]
                            color = newClock[i]
    
                            
                            if color in ["r","y","m","w"]:
                                tempHours += currentSquare
                            if color in ["g","y","c","w"]:
                                tempMinutes += currentSquare * 5
                            if color in ["b","m","c","w"]:
                                tempSeconds += currentSquare * 5
                            
                        if tempHours == hours and tempMinutes == minutes and tempSeconds == seconds:
                            print(newClock, end=" ")

    print("\n")