file = open("whatbase.in","r")
data = file.read().strip().split("\n")
file.close()
k = int(data[0])

def base_10(number,base):
    return number[2] + number[1]*base + number[0]*base**2

answers = []

for i in range(0,k):
    s1,s2 = [],[]
    n1,n2 = list(map(int,data[i+1].split(" ")))
    for digit in str(n1):
        s1.append(int(digit))
    for digit in str(n2):
        s2.append(int(digit))
    x,y = 10,10
    while 1:
        if base_10(s1,x) > base_10(s2,y):
            y += 1
        elif base_10(s2,y) > base_10(s1,x):
            x += 1
        else:
            answers.append([x,y])
            break        
            
file = open("whatbase.out","w")
for ans in answers:
    file.write(str(ans[0]) + " " + str(ans[1]) + "\n")
file.close()