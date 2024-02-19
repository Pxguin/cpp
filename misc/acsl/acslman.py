fpointer = open("inputs.txt", "r")
lines = fpointer.read().replace(" ","").split("\n")
fpointer.close()

additions = ["  O", "\n+", "=", "[]", "=", "+", "\n []", "\n /", " \\"]

for line in lines:
    newLine = line.split(",")

    word = newLine[0]
    letters = newLine[2:]
    
    mistakes = 0
    
    stringCopy = []
    stringCopy.extend(word)
    stringCopy = list(set(stringCopy))
    
    for letter in letters:
        if not letter in word:
            mistakes += 1
            if mistakes == 9:
                break
                
        else:
            if letter in stringCopy:
                stringCopy.remove(letter)
                if stringCopy == []:
                    break

    if mistakes == 0:
        print("NONE")
    else:
        for i in additions[:mistakes]:
            print(i, end="")

    print("\n\n")