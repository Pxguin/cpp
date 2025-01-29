file = open("tttt.in","r")
board = file.read().strip().split("\n")
board = board[0]+board[1]+board[2]
file.close()
combos = [board[:3],board[3:6],board[6:],board[0]+board[3]+board[6],board[1]+board[4]+board[7],board[2]+board[5]+board[8],board[0]+board[4]+board[8],board[2]+board[4]+board[6]]

team_s = []
team_d = []
single = 0
double = 0
for combo in combos:
    cows = list(set([cow for cow in combo]))
    cows.sort()
    if len(cows) == 1 and cows not in team_s:
        team_s.append(list(cows))
        single += 1
    elif len(cows) == 2 and cows not in team_d:
        team_d.append(list(cows))
        double += 1
file = open("tttt.out","w")
file.write(str(single)+"\n"+str(double))
file.close()