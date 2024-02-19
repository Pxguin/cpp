fpointer = open("searchdata.txt", "r")
inputs = fpointer.read().split("\n")
fpointer.close()

words = inputs[0].split(", ")
searches = inputs[1:]

addWord = True
searchWords = []

for searchWord in searches:
    for word in words:

        if (len(searchWord) > len(word) and "*" not in searchWord) or (len(searchWord) - len(word) > 1 and "*" in searchWord):
            addWord = False
        else:
            if searchWord[0] == "*" and not searchWord[-1] == "*":
                cutWord = searchWord[1:]
                wordLength = len(cutWord)
                search = word[-1*wordLength:]
    
    
            elif searchWord[-1] == "*" and not searchWord[0] == "*":
                cutWord = searchWord[:-1]
                wordLength = len(cutWord)
                search = word[:wordLength]
    
            elif "?" in searchWord:
                cutWord = searchWord  
                wordLength = len(cutWord)
                search = word

            else:
                addWord = False
            
        
        if addWord:
            for i in range(wordLength):
                if cutWord[i] != search[i] and cutWord[i] != "?":
                    addWord = False


        if addWord:
            searchWords.append(word)
    
        addWord = True

    if len(searchWords) == 0:
        print("No match")
    else:
        string = ""
        for i in searchWords:
            string += (i + ", ")
        string = string[:-2]
        print(string)
    
    searchWords.clear()
                 