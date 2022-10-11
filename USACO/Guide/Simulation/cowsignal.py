with open('cowsignal.in', 'r') as fin:
    M, N, K = map(int, fin.readline().split())
    signal = [fin.readline().strip() for _ in range(M)]

with open('cowsignal.out', 'w') as fout:
    for row in signal:
        for _ in range(K):
            fout.write(''.join([char * K for char in row]) + '\n')