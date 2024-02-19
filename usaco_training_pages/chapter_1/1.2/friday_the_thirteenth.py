"""
ID: arihaow2
LANG: PYTHON3
TASK: friday
"""

fin = open("friday.in", 'r')
fout = open("friday.out", 'w')

n = fin.readline()
leap = 0
year = 0
day = 0

thirteen = [0, 0, 0, 0, 0, 0, 0]

dotw = 1

months = [
    [31],
    [28],
    [31],
    [30],
    [31],
    [30],
    [31],
    [31],
    [30],
    [31],
    [30],
    [31]
]

years = int(n) + 1900

while year != int(n):

    currYear = year + 1900

    if currYear % 100 != 0 and currYear % 4 == 0 or currYear % 400 == 0:
        leap = 1
    else:
        leap = 0
    currentMonth = 0

    for i in months:
        if leap == 1:
            months[1][0] = 29
        else:
            months[1][0] = 28

        currentMonth += 1

        day = 1
        while day <= int(*i):

            if day == 13:
                thirteen[dotw-1] += 1

            if dotw == 7:
                dotw = 1
            else:
                dotw += 1


            day += 1

    year += 1

fout.write(str(thirteen[5]))
fout.write(" ")
fout.write(str(thirteen[6]))
fout.write(" ")
fout.write(str(thirteen[0]))
fout.write(" ")
fout.write(str(thirteen[1]))
fout.write(" ")
fout.write(str(thirteen[2]))
fout.write(" ")
fout.write(str(thirteen[3]))
fout.write(" ")
fout.write(str(thirteen[4]))
fout.write("\n")
fout.close()