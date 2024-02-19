answerStr = ""
guess = ""
answer = []

green = 0
yellow = 0

'''for i in range(3):
    answerStr += input()

for i in range(3):
    guess += input()'''

answerStr = ""
guess = ""

answer.extend(answerStr)

for cow in range(9):
    if guess[cow] in answer:
        if answerStr[cow] == guess[cow]:
            green += 1
        else:
            yellow += 1
        answer.remove(guess[cow])

print(green)
print(yellow)