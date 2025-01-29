import sys

n = int(input())
metalinput = tuple(map(int,input().split(" ")))
k = int(input())

metals = {}
recipes = {}

for i in range(n):
    metals[i+1] = metalinput[i]
    recipes[i+1] = []

for i in range(k):
    recipeinput = list(map(int,input().split(" ")))
    recipes[recipeinput[0]] = recipeinput[2:]

check = [n]
flag = False
metal_n = 0
total = []

while flag == False:
    temp = []
    has_all_metals = True
    for metal in check:
        metals[metal] -= 1
        if metals[metal] < 0:
            has_all_metals = False
            if recipes[metal] != []:
                for i in recipes[metal]:
                    temp.append(i)
                metals[metal] = 0
                check = list(temp)
            else:
                flag = True
        else:
            total.append(metal)

    if flag == True:
        break;
    elif has_all_metals == True:
        metal_n += 1
        check = list(total)
        total = []

print(metal_n)