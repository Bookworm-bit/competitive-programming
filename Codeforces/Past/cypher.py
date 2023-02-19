t = int(input())

for i in range(t):
    n = int(input())
    wheel = list(map(int, input().strip().split(" ")))

    for i in range(n):
        move = input().split(" ")

        up = move[1].count("U")
        down = move[1].count("D")

        wheel[i] -= up
        wheel[i] += down
        wheel[i] %= 10
    
    out = ""

    for item in wheel:
        out += str(item) + " "
    print(out)