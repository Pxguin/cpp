file = open("tracing.in","r")
file_input = file.read().strip().split("\n")
file.close()
n,t = map(int,file_input[0].split(" "))
result = [int(i) for i in file_input[1]]
events = []
for i in file_input[2:]:
    events.append(list(map(int,i.split(" "))))
events.sort()
for i in range(t):
    events[i] = events[i][1:]
    events[i][0] -= 1
    events[i][1] -= 1
patient_zeros = 0
k_min = 1000
k_max = 0

for i in range(n): # all cows
    is_pzero = False
            
    if result[i] != 1:
        continue
        
    for j in range(t+1): # all k values
        k_values = [j for z in range(n)] # k tracker for every cow
        cows = [0 for z in range(n)]
        cows[i] = 1
            
        for k in range(t): # all handshakes
            change = [False,False]
            event = events[k]
            if cows[event[0]] == 1: # simulation
                if k_values[event[0]] > 0:
                    k_values[event[0]] -= 1
                    change[1] = True
                    
            if cows[event[1]] == 1:
                if k_values[event[1]] > 0:
                    k_values[event[1]] -= 1
                    change[0] = True
            
            if change[0] == True: # new infected cows after the handshake
                cows[event[0]] = 1
            if change[1] == True:
                cows[event[1]] = 1
                
        if cows == result: 
            k_min = min(k_min,j)
            k_max = max(k_max,j)
            is_pzero = True
            
    if is_pzero == True:
        patient_zeros += 1

if k_max == t:
    k_max = "Infinity"

file = open("tracing.out","w")
file.write(str(patient_zeros)+" "+str(k_min)+" "+str(k_max))
file.close()