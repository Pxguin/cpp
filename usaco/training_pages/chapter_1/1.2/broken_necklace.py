fin = open("beads.in", 'r')
fout = open("beads.out", 'w')

n = int(fin.readline().strip())
beads = fin.readline().strip()
countR = 0
countB = 0
countW = 0

backCountR = 0
backCountB = 0
backCountW = 0

countBeads = 0
countBeads2 = 0

n2x = 2*n
beads2x = beads+beads

forward = ""
backward = ""

index = 0

for i in range(n, 2*n):
    if beads2x[i] == beads2x[i-1] or beads2x[i] == "w":
        countBeads2 += 1
        continue
    else:
        countBeads2 = 0

        for j in beads2x[i:]:
            if j == "w":
                continue
            else:
                forward = j
                break
        
        for count, j in enumerate(beads2x[i-len(beads):]):
            if j == forward or j == "w":
                if j == "r":
                    countR += 1
                elif j == "b":
                    countB += 1
                elif j == "w":
                    countW += 1
            else:
                break
        index = count + len(beads)

        if countR > countB:
            countR += countW
        else:
            countB += countW

        for j in beads2x[i-1:0:-1]:
            if j == "w":
                continue
            else:
                backward = j
                break
                
        for count, j in enumerate(beads2x[i-1:0:-1] + beads2x[0]):
            if count == 2*n-index:
                break
            if j == backward or j == "w":
                if j == "r":
                    backCountR += 1
                elif j == "b":
                    backCountB += 1
                elif j == "w":
                    backCountW += 1
            else:
                break   
                
        if backCountR > backCountB:
            backCountR += backCountW
        else:
            backCountB += backCountW

    if countR + countB + backCountR + backCountB > countBeads:
        countBeads = countR + countB + backCountR + backCountB
        
    countR = 0
    countB = 0
    backCountR = 0
    backCountB = 0
    backCountW, countW = 0, 0

fout.write(str(max(countBeads, countBeads2)) + "\n")
fout.close()