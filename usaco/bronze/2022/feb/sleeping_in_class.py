t = int(input())

for i in range(t):
    n = int(input())
    log = list(map(int,input().split(" ")))
    goal = max(log)
    end = sum(log)
    changes = 0
    total = 0

    if not goal == 0:
        while 1:
            if end % goal == 0:
                total = 0
                flag = False
                changes = 0
                add = 0
                
                for i in range(n):
                    total += log[i]
                    add += 1
                    if add > 1:
                        changes += 1
                    if goal == total:
                        total = 0
                        add = 0
                    elif total > goal:
                        goal += 1
                        flag = True
                        break
    
                if not flag:
                    break
                
            else:
                goal += 1
                
    print(changes)