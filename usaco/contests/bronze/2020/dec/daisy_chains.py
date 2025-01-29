flowerNumber = int(input())
flowers = list(map(int, (input()).split(" ")))

average = 0

for i in range(flowerNumber):
    for j in range(flowerNumber-i):
        flowerRange = flowers[i:j+1+i]
        if sum(k for k in flowerRange) / len(flowerRange) in flowerRange:
            average += 1

print(average)