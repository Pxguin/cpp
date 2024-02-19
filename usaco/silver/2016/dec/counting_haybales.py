file = open("haybales.in", "r")
m = file.read().strip().split("\n")
file.close()
n, q = list(map(int, m[0].split(" ")))
haybales = list(map(int, m[1].split(" ")))
haybales.sort()
file = open("haybales.out","w")

low = 0
high = len(haybales) - 1

def search(i):
    low = 0
    high = len(haybales)-1
    while low <= high:
        mid = (low+high)//2
        if haybales[mid] == i:
            return mid+1
        elif haybales[mid] < i:
            low = mid+1
        else:
            high = mid-1
    return low
for j in m[2:]:
    target = list(map(int,j.split(" ")))
    file.write(str(search(target[1])-search(target[0]-1))+"\n")
file.close()