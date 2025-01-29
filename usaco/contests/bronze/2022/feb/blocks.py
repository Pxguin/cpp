n = int(input())
blocks = [input() for i in range(4)]
words = [input() for i in range(n)]
word_set = []

for word in words:
    for i in range(len(word)):
        letter = word[i]
        word_set.append([])
        correct = False
        for j in range(4):
            if letter in blocks[j]:
                word_set[i].append(j)
                correct = True
        if correct == False:
            word_set = []
            break
    total_words = []
    new_set = list(word_set)

    for i in range(len(word_set)):
        total_words += word_set[i]

    first = True

    if not total_words:
        print("NO")
    else:
        while not word_set == new_set or first:
            first = False
            for i in range(len(word_set)):
                for j in range(len(word_set[i])):
                    letter = word_set[i][j]
                    if total_words.count(letter) == 1:
                        total_words.remove(letter)
                        new_set[i] = [-1]
                        
            word_set = list(new_set)
    
        if not total_words:
            print("YES")
        else:
            remain = 0
            for i in word_set:
                if not all(j == -1 for j in i):    
                    remain += 1
            if len(set(total_words)) < remain:
                print("NO")
            else:
                print("YES")
        
        word_set = []