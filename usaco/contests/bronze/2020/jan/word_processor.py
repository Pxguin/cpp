file = open("word.in", "r")
first_line,words = file.read().strip().split("\n")
n,k = map(int,first_line.split(" "))
file.close()
words = words.split(" ")

line_len = 0
line = ""
lines = []

for i in words:
    if line_len + len(i) > k:
        lines.append(line[:-1])
        line = i + " "
        line_len = len(i)
    else:
        line += i + " "
        line_len += len(i)
lines.append(line[:-1])
file = open("word.out","w")
for line1 in lines:
    file.write(line1+"\n")
file.close()