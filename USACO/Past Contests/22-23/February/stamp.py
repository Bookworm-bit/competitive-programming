def rotate(stamp, k):
    new_stamp = []
    for j in range(k):
        row = []
        for i in range(k):
            row.append(stamp[k-i-1][j])
        new_stamp.append(row)
    return new_stamp

t = int(input())
for _ in range(t):
    input()
    n = int(input())
    grid = [list(input().strip()) for _ in range(n)]

    k = int(input())
    stamp = [list(input().strip()) for _ in range(k)]
    stamps = [stamp]
    for i in range(3):
        stamps.append(rotate(stamps[-1], k))

    test = [["."] * n] * n
    breaks = False
    while test != grid:
        for s in stamps:
            for i in range(n):
                if breaks:
                    break
                for j in range(n):
                    if breaks:
                        break
                    if (i + k < n) and (j + k < n):
                        if breaks:
                            break
                        for l in range(k):
                            if breaks:
                                break
                            for m in range(k):
                                if breaks:
                                    break
                                thing = [["."] * n] * n
                                thing[i + l][j + m] = stamp[l][m]
                                all_ast = []
                                for a in range(n):
                                    if breaks:
                                        break
                                    for b in range(n):
                                        if thing[a][b] == "*":
                                            if thing[a][b] == grid[a][b]:
                                                continue
                                                all_ast.append(True)
                                            else:
                                                breaks = True
                                                break
                                if all(all_ast):
                                    test = thing