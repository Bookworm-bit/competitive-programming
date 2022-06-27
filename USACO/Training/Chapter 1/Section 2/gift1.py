"""
ID: Devworm
LANG: PYTHON3
TASK: gift1
"""

with open('gift1.in', 'r') as fin:
    data = fin.readlines()
    NP = int(data[0])
    names = data[1:NP+1]
    for i in range(NP):
        names[i] = names[i].strip()
    money = {names[i] : 0 for i in range(NP)}
    giving_blocks = data[NP+1:]

    for i in range(len(giving_blocks)):
        if i != len(giving_blocks) - 1:
            if giving_blocks[i].strip() in names and ' ' in giving_blocks[i+1]:
                giver = giving_blocks[i].strip()
                total_giving_amount = int(giving_blocks[i+1].split(' ')[0])
                receiver_count = int(giving_blocks[i+1].split(' ')[1])
                receivers = [giving_blocks[i+2+j].strip() for j in range(receiver_count)]
                try:
                    remaining = total_giving_amount % receiver_count
                except ZeroDivisionError:
                    remaining = 0
                money[giver] -= total_giving_amount
                money[giver] += remaining

                for reciever in receivers:
                    money[reciever] += (total_giving_amount - remaining) // receiver_count

with open('gift1.out', 'w') as fout:
    for name in names:
        fout.write("{} {}".format(name, money[name]) + '\n')
    fout.close()
