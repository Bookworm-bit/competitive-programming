n = 100

possible = 0
for i in range(n):
	colors = {
		"red": 0,
		"green": 0,
        "blue": 0
	}

	line = input()
	line = line.split(" ")

	line.pop(0)
	line.pop(0)
	
	for j in range(1, len(line)-2, 2):
		line[j] = line[j][:-1]

	for j in range(1, len(line), 2):
		color = line[j][0:len(line[j])]
		colors[color] = max(int(line[j-1]), colors[color])

	if colors["red"] <= 12 and colors["green"] <= 13 and colors["blue"] <= 14:
		possible += i+1

print(possible)