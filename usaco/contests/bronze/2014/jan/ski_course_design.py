file = open("skidesign.in", "r")
data = list(map(int, file.read().strip().split("\n")))
file.close()

hillNumber = data[0]-1
hills = data[1:]
del data

money = 0

highest = max(hill for hill in hills)
lowest = min(hill for hill in hills)

def binarySearch(l, r, x):
    while l <= r:
        mid = l + (r - l) // 2
        if hills[mid] == x:
            return mid
        elif hills[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1

money2 = 0
count = 1

cutoff1 = 0
cutoff2 = highest-lowest-17

while cutoff2 != 0:
    high = highest
    low = lowest
    
    high -= cutoff2
    low += cutoff1

    hills.append(high)
    hills.append(low)

    hills.sort()

    for hill in hills[binarySearch(0,hillNumber,high)+1:]:
        money2 += (hill-high) ** 2

    for hill in hills[:binarySearch(0,hillNumber,low)+1]:
        money2 += (low-hill) ** 2

    if money2 <= money or count == 1:
        count = 0
        money = money2
    else:
        break
    
    money2 = 0

    hills.remove(high)
    hills.remove(low)
    
    cutoff2 -= 1
    cutoff1 += 1

file = open("skidesign.out", "w")
file.write(str(int(money)))
file.close()