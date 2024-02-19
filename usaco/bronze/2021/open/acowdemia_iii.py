n,m = list(map(int,input().split(" ")))
grid = [["." for i in range(m+2)]]
for i in range(n):
    grid.append(["."])
    for j in input():
        grid[i+1].append(j)
    grid[i+1].append(".")
grid.append(["." for i in range(m+2)])

friends = []
pairs = 0

current_pair = []
for i in range(1,n+1):
    for j in range(1,m+1):
        if grid[i][j] == "G":
            neighbors = 0

            neighbor_pair = []

            for neighbor in ((i-1,j),(i+1,j),(i,j+1),(i,j-1)):
                if grid[neighbor[0]][neighbor[1]] == "C":
                    neighbors += 1
                    neighbor_pair.append(tuple(neighbor))

            if neighbors == 2:
                neighbor_pair.sort()
                friends.append(tuple(neighbor_pair))
                
            elif neighbors > 2:
                for pair in (((i-1,j),(i+1,j)),((i,j-1),(i,j+1))):
                    if grid[pair[0][0]][pair[0][1]] == "C" and grid[pair[1][0]][pair[1][1]] == "C":
                        pairs += 1
                        break

friends = set(friends)
pairs += len(friends)
print(pairs)