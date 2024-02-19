'''
given a string, find:
1. num words in string
2. longest word. Print all if tie
3. # of unique letters
4. most frequent letter
5. Most frequently used word other than THE

(assume the string is all caps?)
'''

words = []

longestWord = [""]

count = 0
mostFrequent = ["a"]

letterCounters = {}

count2 = 0
mostFrequent2 = None

wordCounters = {}

string = "IN A RIGHT TRIANGLE THE LENGTH OF THE HYPOTENUSE EQUALS THE SUM OF THE SQUARES OF THE LEGS"


# Number 1
for word in string.split(" "):
    if not word == "":
        words.append(word.strip())


# Numbers 2, 3, 4, 5
for word in words:
    if word.lower() in wordCounters.keys():
        wordCounters[word.lower()] += 1
    else:
        wordCounters[word.lower()] = 1
    
    if len(word) > len(longestWord[0]):
        longestWord = [word]
    elif len(word) == len(longestWord[0]):
        longestWord.append(word)

    for letter in word:
        if letter.lower() in letterCounters.keys():
            letterCounters[letter.lower()] += 1
        else:
            letterCounters[letter.lower()] = 1

del wordCounters["the"]

mostFrequent2 = [list(wordCounters.keys())[0]]

for key in wordCounters.keys():
    if wordCounters[key] > wordCounters[mostFrequent2[0]]:
        mostFrequent2 = [key]
    elif wordCounters[key] == wordCounters[mostFrequent2[0]]:
        mostFrequent2.append(key)    

for letter in letterCounters.keys():
    if letterCounters[letter] > letterCounters[mostFrequent[0]]:
        mostFrequent = [letter]
    elif letterCounters[letter] == letterCounters[mostFrequent[0]]:
        mostFrequent.append(letter)    


print("\n1. " + str(len(words)))

print("2. ", end="")

for word in longestWord:
    print(word + " ", end="")

print("")
print("3. " + str(len(letterCounters.keys())))

print("4. ", end="")

for i in mostFrequent:
    print(i + " ", end="")

print("")
print("5. ", end="")

for i in mostFrequent2:
    print(str(i) + " ", end="")

print("")