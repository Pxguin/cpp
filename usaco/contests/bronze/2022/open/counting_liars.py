n = int(input())

greater = []
less = []
lies = 0
min_lies = 10**9

for i in range(n):
    statement = input().split(" ")
    if statement[0] == "G":
        greater.append(int(statement[1]))
    else:
        less.append(int(statement[1]))

for loc in greater+less:
    lies = 0
    for i in greater:
        if loc < i:
            lies += 1
    for i in less:
        if loc > i:
            lies += 1

    min_lies = min(lies, min_lies)

print(min_lies)