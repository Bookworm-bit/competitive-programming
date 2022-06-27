numWord = int(input())
list = [input(), input(), input(), input()]
spell = []
a = [0] * 26
b = [0] * 26
counter = 0

for word in list:
    for letter in set(word):
        a[ord(letter) - 65] += 1
for i in range(numWord):
    spell.append(input())

for word in spell:
    for letter in set(word):
        b[ord(letter) - 65] += 1
        counter += 1
        if a[word.find(letter)] >= b[word.find(letter)]:
            b.append("e")
        if a[ord(letter) - 65] > 4:
            a[ord(letter) - 65] = 0
            if word.count(letter) >= 1:
                a[ord(letter) - 65] += 1
        if a[word.find(letter)] < b[word.find(letter)]:
            b.pop()
    if len(b) == len(a) + counter:
        print("YES")
    else:
        print("NO")
        counter += counter - len(b)
