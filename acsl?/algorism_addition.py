'''
Numerically add two numbers, utilizing digit places and carry.
'''

def add_numeric_strings(str1, str2):
    if len(str1) != len(str2):
        if len(str1) > len(str2):
            max1 = str1
            min1 = str2
        else:
            max1 = str2
            min1 = str1
    else:
        max1 = str1
        min1 = str2


    number = ""
    sum1 = ""
    carry = 0

    min1 = "0"*(len(max1)-len(min1)) + min1

    for i in range(len(max1)-1,-1,-1):
        number = int(max1[i]) + int(min1[i]) + carry

        carry = number // 10
        number = number % 10

        sum1 = str(number) + sum1

    if carry > 0:
        sum1 = str(carry) + sum1

    return "\n" + sum1

print(add_numeric_strings(input(),input()))