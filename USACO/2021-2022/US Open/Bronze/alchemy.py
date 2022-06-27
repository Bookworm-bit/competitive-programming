N = int(input())
metal_amounts = list(map(int, input().split()))
K = int(input())
product = []
recip = []

for i in range(K):
    temp_input = input().split()
    product.append(int(temp_input[0]))
    recip.append([int(item) for item in temp_input[2:]])

# First item of a tuple is the name and second is the recipe
recipe_list = sorted(list(zip(product, recip)))

def transform_metals(recipe_list, metal_amounts):
    global i
    global N
    desired = recipe_list[i]
    bools = []
    
    for item in desired[1]:
        if metal_amounts[desired[0] - 1] > 0:
            bools.append(True)
        else:
            bools.append(False)
    
    if bools.count(False) == 0:
        for item in desired[1]:
            metal_amounts[item - 1] = metal_amounts[item - 1] - 1
    
    i += 1
    if i < len(recipe_list):
        return transform_metals(recipe_list, metal_amounts)
    else:
        return metal_amounts[N - 1]

print(transform_metals(recipe_list, metal_amounts))
