import math
import itertools

t = int(input())

def check_all_gcd(a):
    for (a_i, a_j) in itertools.combinations(a, 2):
        if a_i != a_j:
            if math.gcd(a_i, a_j) > 1:
                return True
    return False

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split(" ")))
    print("YES\n" if check_all_gcd(a) else "NO\n")