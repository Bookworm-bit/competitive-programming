n = 100

power_sum = 0
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

	power_sum += colors["red"] * colors["green"] * colors["blue"]

print(power_sum)