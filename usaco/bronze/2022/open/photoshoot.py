n = int(input())
cows = input()
new_cows = ""

dir = 0 # 0 = even, 1 = odd
flips = 0

for i in range(0,n,2):
    if cows[i] != cows[i+1]:
        new_cows += cows[i] + cows[i+1]

dir = 0 if new_cows[0] == "H" else 1

for i in range(2,len(new_cows),2):
    new_dir = 0 if new_cows[i] == "H" else 1
    if new_dir != dir:
        dir = new_dir
        flips += 1

if dir == 1:
    flips += 1

print(flips)