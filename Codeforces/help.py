t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split(" ")))
    count = 0

    for i in range(n):
        for j in range(n):
            if i >= 1 and i != j and abs(a[i] - a[j]) == abs(max(a) - min(a)):
                print(a[i])
                print(a[j])
                count += 1
            else:
                continue
    
    print(count)
