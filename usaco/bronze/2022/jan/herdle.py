answerStr = ""
guess = ""
answer = []
used = []

green = 0
yellow = 0

for i in range(9):
    used.append(False)

for i in range(3):
    answerStr += input()

for i in range(3):
    guess += input()

answer.extend(answerStr)

for cow in range(9):
    if guess[cow] in answer:
        if answerStr[cow] == guess[cow]:
            green += 1
            used[cow] = True
            answer.remove(guess[cow])
for cow in range(9):
    if  (guess[cow] in answer) and (not used[cow]):
        yellow += 1
        answer.remove(guess[cow])

print(green)
print(yellow)