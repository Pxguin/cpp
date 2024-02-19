file = open("waves.txt", "r")
data = list(map(int, file.read().strip().split(" ")))
file.close()

n = data[0]
waves = data[1:]
total = 0
ascending = False

while n > 0:
    while total+n > len(waves):
        waves += data[1:]

    waves[total:total+n] = sorted(waves[total:total+n], reverse=ascending)
    
    total += n
    n -= 1
    ascending = not ascending

waves[total:] = sorted(waves[total:], reverse=ascending)

for wave in waves:
    print(wave, end=" ")