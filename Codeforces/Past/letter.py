n, m = tuple(map(int, input().strip().split()))
lines = []

for i in range(n):
    lines.append(input())

start_x = 100000
start_y = 100000
end_x = 0
end_y = 0

for i in range(n):
    if "*" in lines[i]:
        for j in range(m):
            if lines[i][j] == "*":
                start_x = min(start_x, j)
                start_y = min(start_y, i)
                end_x = max(end_x, j)
                end_y = max(end_y, i)

for i in range(start_y, end_y + 1):
    print(lines[i][start_x:end_x + 1])