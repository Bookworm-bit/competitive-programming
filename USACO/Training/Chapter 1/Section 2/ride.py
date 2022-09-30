"""
ID: Devworm
LANG: PYTHON3
TASK: ride
"""

import math

with open('ride.in', 'r') as fin:
    eyes = fin.readlines()
    letters = eyes[0]
    a = [ord(l) - 64 for l in letters]
    ship = eyes[1]
    x = [ord(s) - 64 for s in ship]

with open('ride.out', 'w') as fout:
    fout.write("{}\n".format("GO" if math.prod(a) % 47 == math.prod(x) % 47 else "STAY"))
