file = open("paint.in","r")
a,b = list(map(int,file.readline().split(" ")))
c,d = list(map(int,file.readline().split(" ")))
file.close()

length = (b-a)+(d-c)-max(min(b,d)-max(a,c),0)
file = open("paint.out","w")
file.write(str(length))
file.close()