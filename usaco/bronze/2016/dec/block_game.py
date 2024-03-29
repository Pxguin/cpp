file = open("blocks.in", "r")
data = file.read().strip().split("\n")
file.close()

shownWords = int(data[0])
words = []
for wordPair in data[1:]:
    words.append(wordPair.split(" "))

alphabet = {"a":[],"b":[],"c":[],"d":[],"e":[],"f":[],"g":[],"h":[],"i":[],"j":[],"k":[],"l":[],"m":[],"n":[],"o":[],"p":[],"q":[],"r":[],"s":[],"t":[],"u":[],"v":[],"w":[],"x":[],"y":[],"z":[]}

alphabetKeys = alphabet.keys()

for wordPair in words:
    for letter in alphabetKeys:
        alphabet[letter].append(max(wordPair[0].count(letter),wordPair[1].count(letter)))

file = open("blocks.out", "w")
for i in alphabetKeys:
    letterList = alphabet[i]
    totalSum = 0
    for j in range(shownWords):
        largest = max(letterList)
        totalSum += largest
        letterList.remove(largest)
    
    file.write(str(totalSum)+"\n")
file.close()