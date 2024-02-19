'''
Is an array sorted? Must only consider every element once.
'''

def is_sorted(ar):
    trend = ""

    if ar[0] > ar[1]:
        trend = "decrease"
    elif ar[0] < ar[1]:
        trend = "increase"

    if len(ar) == 1:
        return True
    else:
        for count, i in enumerate(ar[2:]):
            if trend == "increase":
                if i < ar[count+1]:
                    return False
            elif trend == "decrease":
                if i > ar[count+1]:
                    return False
            elif trend == "":
                if i > ar[count+1]:
                    trend = "increase"
                elif i < ar[count+1]:
                    trend = "decrease"

        return True

        

string = input("")
sortList = []

for i in string.split(","):
    sortList.append(int(i))

print(is_sorted(sortList))