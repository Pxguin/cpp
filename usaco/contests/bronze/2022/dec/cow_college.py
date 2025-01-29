n = int(input())
c = list(map(int,input().split(" ")))
c.sort()

answer = c[0]
money = c[0]*n

for i in range(1,n):
    if c[i] != c[i-1]:
        will_pay = n-i
        if c[i]*will_pay > money:
            answer = c[i]
            money = c[i]*will_pay

print(money,answer)