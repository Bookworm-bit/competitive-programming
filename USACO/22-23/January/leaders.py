n = int(input())
cows = range(1, n+1)

breeds = input().strip()
g_ids = [i+1 for i in range(n) if breeds[i] == "G"]
h_ids = [i+1 for i in range(n) if breeds[i] == "H"]

ends = list(map(int, input().split(" ")))

lists = [list(range(cows[i], ends[i]+1)) for i in range(n)]

strg = list(map(str, g_ids))
strh = list(map(str, h_ids))

all_breed = []
for (idx, l) in enumerate(lists):
    lt = list(map(str, l))
    # print(l)

    if "".join(strh) in "".join(lt) or "".join(strg) in "".join(lt):
        all_breed.append(idx)

count = 0
sus = 0
for (i, l) in enumerate(lists):
    # Both only have lists containing the other leader
    for c in l:
        if i in lists[c-1]:
            sus += 1
            break
    
    # One contains a leader and the other contains a census
    for c in l:
        if (c-1) in all_breed:
            count += 1
            break


count += sus / 2
print(int(count - 1))