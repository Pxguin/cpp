letters = []
values = []


for i in range(5):
    letters.append(input(""))

for i in letters:
    values.append(ord(i) - 95)

for i in range(5):
    if values[i] <= 5:
        values[i] *= 2
    elif values[i] <= 10:
        values[i] %= 3
        values[i] *= 5
    elif values[i] <= 15:
        values[i] //= 4
        values[i] *= 8
    elif values[i] <= 20:
        values[i] = (sum(int(i) for i in str(values[i]))*10)%26
    else:
        for j in range(values[i]-1,0,-1):
            if values[i] % j == 0:
                values[i] = (j * 12) % 26
                break

letters.clear()

for i in values:
    if i > 0:
        letters.append("Z")
    else:
        letters.append(chr(i-1+65))

print("\n")

for i in range(5):
    print(str(i+1) + ". " + letters[i])
    