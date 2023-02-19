t = int(input())

for i in range(t):
    score = 0
    n = int(input())
    balloon = input().strip()

    for j in range(n):
        if j == balloon.find(balloon[j]):
            score += 2
        else:
            score += 1
    
    print(score)