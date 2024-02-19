fpointer = open("sentence.txt", "r")
inputs = fpointer.read().split("\n")
fpointer.close()

order = inputs[-1]
words = {"T":["the"]}

for i in inputs[1:-1]:
    words[i[0]] = i[2:].split(" ")

completedSentence = ""

sentences = []


for sentence in order.split(" "):
    for i in range(len(sentence[1:])):
        word = sentence[i+1]
        if word == "A":
            completedSentence += "a"
            if words[sentence[i+2]][0][0] in ["a","e","i","o","u"]:
                completedSentence += "n"
        else:
            completedSentence += words[word][0]

            words[word].append(words[word][0])
            words[word].pop(0)

        completedSentence += " "

    completedSentence = completedSentence[:-1]

    if sentence[0] == "D" or sentence[0] == "I":
        completedSentence += "."
    elif sentence[0] == "E":
        completedSentence += "!"
    else:
        completedSentence = "what " + completedSentence + "?"

    completedSentence = completedSentence[0].upper() + completedSentence[1:]

    sentences.append(completedSentence)
    completedSentence = ""

for sentence in sentences:
    print(sentence + " ", end="")