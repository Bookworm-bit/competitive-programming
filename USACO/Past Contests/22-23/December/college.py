n = int(input().strip())
willing_tuition = list(map(int, input().strip().split(" ")))

profit_list = []
willing_tuition = sorted(willing_tuition)

for (idx, t) in enumerate(willing_tuition):
    profit_list.append(t * (n - idx))

print(f"{max(profit_list)} {willing_tuition[profit_list.index(max(profit_list))]}")