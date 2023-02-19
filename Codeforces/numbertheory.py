t = int(input())

def gcd(m, n):
    if n == 0:
        return m
    
    print(f"gcd({n}, {m%n})")
    return gcd(n, m%n)

xr = range(1, 1000)
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split(" ")))

    rx = 0
    out = False
    for x in xr:
        x_check = []
        for i in range(n):
            for j in range(i+1, n):
                x_check.append(gcd(a[i]+x, a[j]+x) == 1)
        
        if all(x_check):
            rx = x
            out = True
            print("YES")
            break
    
    if not out:
        print("NO")