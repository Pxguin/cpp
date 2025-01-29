t = int(input())

possible_c = []
for i in range(1,11):
    for j in range(1,11):
        for k in range(1,11):
            for l in range(1,11):
                possible_c.append([i,j,k,l])

def compare(a,b):
    wins_a = 0
    wins_b = 0

    for i in a:
        for j in b:
            if i > j:
                wins_a += 1
            elif i < j:
                wins_b += 1

    return wins_a > wins_b

for i in range(t):
    dice = list(map(int,input().split(" ")))
    a = dice[:4]
    b = dice[4:]
    flag = False
    for c in possible_c:
        if (compare(a,b) and compare(b,c) and compare(c,a)) or (compare(b,a) and compare(c,b) and compare(a,c)):
            flag = True
            print("yes")
            break
    if flag == False:
        print("no")