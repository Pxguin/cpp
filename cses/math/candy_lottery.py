n, k = list(map(int,input().split()))
denom = k**n
num = 0

for j in range(k):
    num += j**n

print('%.6f' %(k-num/denom))