"""
ID: Devworm
LANG: PYTHON3
TASK: beads
"""


def check_idx(idx):
    return idx % N


with open(r'.\Section 2\beads.in', 'r') as fin:
    data = fin.readlines()
    data = [x.strip() for x in data]
    N = int(data[0].strip())
    beads = data[1].strip()

idx = 0
possibilities = {i: 0 for i in range(N)}

for i in range(N):
    unique = 0
    while True:
        if idx == N:
            idx = 0
            print("ok")

        if beads[idx] == 'w':
            print("white")
            possibilities[idx] += 1
            if check_idx(idx + 1) == 'w':
                possibilities[i] += 1
                idx += 3   
            else:
                idx += 2 
            continue
        elif beads[idx] == 'b':
            print("blue")
            unique += 1
            
            if check_idx(idx + 1) == 'b':
                possibilities[i] += 2
                idx += 2
                print("next blue")
                continue
            elif check_idx(idx + 1) == 'w':
                possibilities[i] += 1
                idx += 2
                print("next white")
                continue
            elif check_idx(idx + 1) == 'r':
                if unique < 2:
                    possibilities[i] += 2
                    idx += 3
                    unique += 1
                    print("next red")
                    continue
                else:
                    print("too many unique")
                    break
            else:
                break
        elif beads[idx] == 'r':
            print("red")
            unique += 1
            
            if check_idx(idx + 1) == 'r':
                possibilities[i] += 2
                idx += 2
                print("next red")
                continue
            elif check_idx(idx + 1) == 'w':
                possibilities[i] += 1
                idx += 2
                print("next white")
                continue
            elif check_idx(idx + 1) == 'b':
                if unique < 2:
                    possibilities[i] += 2
                    idx += 3
                    unique += 1
                    print("next blue")
                    continue
                else:
                    print("too many unique")
                    break
            else:
                break
        else:
            break

with open(r'.\Section 2\beads.out', 'w') as fout:
    fout.write(f'{max(possibilities.values())}\n')