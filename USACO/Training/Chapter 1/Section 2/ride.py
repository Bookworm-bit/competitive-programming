"""
ID: Devworm
LANG: PYTHON3
TASK: ride
"""
fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')
eyes = fin.readlines()

import math

letters = eyes[0]
a = [ord(l) - 64 for l in letters]

ship = eyes[1]

x = [ord(s) - 64 for s in ship]

if (math.prod(a) % 47 == math.prod(x) % 47):
    fout.write ("GO" + '\n')
else:
    fout.write ("STAY" + '\n')
