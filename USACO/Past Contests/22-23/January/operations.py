q = int(input())

for _ in range(q):
    s = input().strip()

    o_ids = [i for (i, c) in enumerate(s) if c == "O"]

    if len(s) > 2:
        if o_ids != []:
            thingery = {}
            for o in o_ids:
                if o > 0 and o < len(s) - 1:
                    if s[o+1] == "O":
                        thingery[o] = 2
                    else:
                        thingery[o] = 1
            
            if 2 in thingery.values():
                if s[list(thingery.keys())[list(thingery.values()).index(2)]-1] == "M":
                    print(len(s) - 3)
                else:
                    print(len(s) - 2)
            elif 1 in thingery.values():
                if s[list(thingery.keys())[0]-1] == "M":
                    print(len(s) - 2)
                else:
                    print(len(s) - 1)
            else:
                print(-1)
        else:
            print(-1)
    else:
        print(-1)