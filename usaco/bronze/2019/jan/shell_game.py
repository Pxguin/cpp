file = open("shell.in", "r")
data = file.read().strip().split("\n")
file.close()

shells = [1,2,3]
swaps = data[1:]
for i in range(len(swaps)):
    swaps[i] = list(map(int, swaps[i].split(" ")))
guesses = [0,0,0]

for swap in swaps:
    for i in range(3):
        if shells[i] == swap[0]:
            shells[i] = swap[1]
        elif shells[i] == swap[1]:
            shells[i] = swap[0]

        if swap[2] == shells[i]:
            guesses[i] += 1

file = open("shell.out", "w")
file.write(str(max(guesses)))
file.close()