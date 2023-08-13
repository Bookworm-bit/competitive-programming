# the cake is not a lie
def solution(s):
    n = len(s)

    for i in range(1, n+1):
        if n % i == 0:
            if s[:i] * (n // i) == s:
                return n // i