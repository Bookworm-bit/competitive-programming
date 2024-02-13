t = int(input().strip())

for _ in range(t):
    input()
    n, m = tuple(map(int, input().strip().split(" ")))
    test_in = []
    test_out = []

    for i in range(m):
        line = input().strip().split(" ")
        test_in.append(line[0])
        test_out.append(line[1])
    
    unique = []
    for cr in range(n):
        rules = []

        for ti in range(m):
            rules.append((test_in[ti][cr], test_out[ti]))

        zero_input = []
        one_input = []
        
        for i in range(m):
            if rules[i][0] == '0':
                zero_input.append(i)
            else:
                one_input.append(i)

        outputs_zero = []
        for index in zero_input:
            outputs_zero.append(rules[index][1])
        
        outputs_one = []
        for index in one_input:
            outputs_one.append(rules[index][1])
        
        largest_zero = 1
        for oz in outputs_zero:
            largest_zero = max(largest_zero, outputs_zero.count(oz))
        
        largest_one = 1
        for oi in outputs_one:
            largest_one = max(largest_one, outputs_one.count(oi))
        
        largest = largest_zero + largest_one
        
        else_output = max(max(len(outputs_zero) - largest_zero, len(outputs_one) - largest_one), 0) 
        
        largest += else_output

        unique.append(largest)

        
    if max(unique) == m:
        print("OK")
    else:
        print("LIE")