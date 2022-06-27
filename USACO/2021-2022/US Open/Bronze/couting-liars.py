from itertools import product
n = int(input())
lessCow = []
greatCow = []
liars = 0

def lie(arr):
    for item in arr:
        first = item[0]
        second = item[1]
        if int(first[2:]) > int(second[2:]):
            pass
        else:
            liars += 1

for i in range(n - 1):
    e = input()
    if e[0] == "L":
        lessCow.append(e)
    if e[0] == "G":
        greatCow.append(e)

arr = []

for x in product(lessCow, greatCow):
    arr.append(x[0] + x[1])

lie(arr)
print(liars)
