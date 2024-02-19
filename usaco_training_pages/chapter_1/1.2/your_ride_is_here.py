fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')
x = fin.readline()
y = fin.readline()
x = x.strip()

productX = 1
productY = 1
modX = 0
modY = 0

for letter in x:
    number = ord(letter) - 64
    productX *= number

for letter in y:
    number = ord(letter) - 64
    productY *= number

modX = productX % 47
modY = productY % 47

if modX == modY:
    fout.write ("GO\n")
else:
    fout.write("STAY\n")
fout.close()