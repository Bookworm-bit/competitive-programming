with open("whereami.in") as file:
    raw = file.read().split("\n")
    n = int(raw[0])
    mailboxes = raw[1]

result = 0
for i in range(1,n+1):
    seqs = []
    unique = True

    for j in range(n-i+1):
        current = mailboxes[j]
        if current in seqs:
            break

        seqs.append(current)

    if unique:
        break

with open("whereami.out", "w") as out:
    out.write("{}\n".format(str(i)))