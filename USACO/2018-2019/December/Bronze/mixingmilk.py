with open(r'mixmilk.in', 'r') as fin:
    data = fin.readlines()
    data = [line.strip() for line in data]

    # First item in buckets is capacity
    # Second item in buckets is current volume
    buckets = {i : data[i].split(" ") for i in range(3)}

    for value in buckets.values():
        value[0] = int(value[0])
        value[1] = int(value[1])

    cycled_states = []

    def check_i(i):
        if i + 1 == 3:
            return "0"
        else:
            return str(i + 1)

    for i in range(4):
        if i > 2:
            i %= 3

        if buckets[i][1] < buckets[int(check_i(i))][1]:
            buckets[int(check_i(i))][1] += buckets[i][1]
            buckets[i][1] = 0
            cycled_states.append([buckets[j][1] for j in range(3)])
        else:
            buckets[int(check_i(i))][1] += (buckets[i][0] - buckets[int(check_i(i))][0])
            buckets[i][1] -= (buckets[i][0] - buckets[int(check_i(i))][0])
            cycled_states.append([buckets[j][1] for j in range(3)])
        
with open(r'mixmilk.out', 'w') as fout:
    for x in range(3):
        fout.write('{} \n'.format(cycled_states[x]))