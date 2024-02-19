t = int(input())

for q in range(t):
    n = int(input())
    cows = list(map(int,input().split(" ")))

    bags = 0
    fail = False

    if n == 1:
        fail = True
        bags = 0
    elif cows[0] > cows[1] or cows[n-1] > cows[n-2]:
        bags = -1
        fail = True
        
    if not fail:
        for i in range(0,n-1,2):
            cow = cows[i]
            if cow > cows[i+1]:
                fail = True
                bags = -1
                break
            elif cow < cows[i+1] and i != n-2:
                difference = cows[i+1] - cow
                bags += 2*difference
                cows[i+2] -= difference
                cows[i+1] -= difference

                if cows[i+2] < 0 or cows[i+1] < 0:
                    bags = -1
                    fail = True
                    break

        if cows[n-1] > cows[n-2]:
            fail = True
            bags = -1

    if not fail:
        min_cow = min(cows)
        if n % 2 == 1:
            if cows[n-1] == min_cow:
                for j in range(0,n-1,2):
                    bags += 2*(cows[j]-min_cow)
            else:
                bags = -1
        else:
            for j in range(0,n-1,2):
                bags += 2*(cows[j]-min_cow)
    
    print(bags)