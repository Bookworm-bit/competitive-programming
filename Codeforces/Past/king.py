import math

raw_start = input()
raw_start = list(raw_start)
start = [ord(raw_start[0]) - 96, int(raw_start[1])]

raw_target = input()
raw_target = list(raw_target)
target = [ord(raw_target[0]) - 96, int(raw_target[1])]

def distance(start, target):
    return math.sqrt((start[0] - target[0])**2 + (start[1] - target[1])**2)

moves = []

while start != target:
    distances = {"L" : 0, "R" : 0, "U" : 0, "D" : 0, "LU" : 0, "LD" : 0, "RD" : 0, "RU" : 0}
    
    L = distance((start[0] - 1, start[1]), target)
    distances["L"] = L
    
    R = distance((start[0] + 1, start[1]), target)
    distances["R"] = R
    
    U = distance((start[0], start[1] + 1), target)
    distances["U"] = U
    
    D = distance((start[0], start[1] - 1), target)
    distances["D"] = D
    
    LU = distance((start[0] - 1, start[1] + 1), target)
    distances["LU"] = LU
    
    LD = distance((start[0] - 1, start[1] - 1), target)
    distances["LD"] = LD
    
    RU = distance((start[0] + 1, start[1] + 1), target)
    distances["RU"] = RU
    
    RD = distance((start[0] + 1, start[1] - 1), target)
    distances["RD"] = RD
    
    optimal = ""
    for key, value in distances.items():
        if value == min(distances.values()):
            moves.append(key)
            optimal = key
            break
    
    if optimal == "L":
        start[0] -= 1
    elif optimal == "R":
        start[0] += 1
    elif optimal == "U":
        start[1] += 1
    elif optimal == "D":
        start[1] -= 1
    elif optimal == "LU":
        start[0] -= 1
        start[1] += 1
    elif optimal == "LD":
        start[0] -= 1
        start[1] -= 1
    elif optimal == "RU":
        start[0] += 1
        start[1] += 1
    elif optimal == "RD":
        start[0] += 1
        start[1] -= 1

print(len(moves))
for m in moves:
    print(m + '\n')