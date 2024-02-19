'''
Randomly display 7 letters, then ask for input and calculate the score of the word if it exists.
"sowpods.txt" is the list of all words
'''

import random

letterValues = {"A":1,"B":3,"C":3,"D":2,"E":1,"F":4,"G":2,"H":4,"I":1,"J":8,"K":5,"L":1,"M":3,"N":1,"O":1,"P":3,"Q":10,"R":1,"S":1,"T":1,"U":1,"V":4,"W":4,"X":8,"Y":4,"Z":10}

letters = []
points = 0

validAnswer = True


letters.append(chr(random.choice([65, 69, 73, 79, 85])))

for i in range(6):
    letters.append(chr(random.randint(65,90)))

fpointer = open("sowpods.txt", "r")
words = fpointer.read()
fpointer.close()

words = words.split("\n")

def binary_search(arr, low, high, x):
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return -1

print("Given characters: ", end="")
for i in letters:
    print(i, end=" ")
answer = input("\nEnter a word: ") 

answer = answer.upper()

for letter in answer:
    if letter in letters:
        letters.remove(letter)
    else:
        validAnswer = False
        break

if validAnswer and binary_search(words, 0, len(words)-1, answer) > -1:
    for i in answer:
        points += letterValues[i]

print("Points: " + str(points))