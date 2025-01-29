# very messy (and old) solution
t = int(input())

for i in range(t):
    n,k = list(map(int,input().split(" ")))
    cows = input()
    
    marker = "G"
    
    spots = []
    for i in range(2):   
        ptr = 0
        while 1:
            if cows[ptr] == marker:
                end1 = ptr+k
                end2 = end1+k
                if end1 >= n-1:
                    end1 = n-1
                if end2 >= n-1:
                    end2 = n-1
    
                max_cow = ptr
                for j in range(end1,end2+1):
                    if cows[j] == marker:
                        max_cow = j
    
                spot2 = max_cow-k
                if spot2 < 0:
                    spot2 = 0
                spots.append([marker,list(reversed(list(j for j in range(spot2,end1+1))))])
                ptr = end2+1
            else:
                ptr += 1
                
            if ptr > n-1:
                break
                
        marker = "H"
        
    field = ["." for i in range(n)]
    spots.sort(key=lambda x: len(x[1]))

    for i in spots:
        for j in i[1]:
            if field[j] == ".":
                field[j] = i[0]
                break
    
    print(len(spots))
    print("".join(field))