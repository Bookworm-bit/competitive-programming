"""
I learned how to do a complete search
An error I made was reading the problem wrong and thinking that it was asking if N can be written as 2 neighboring primes and one
To improve this I could probably make more functions to call certain things and have it return count
"""
 
n, k = tuple(map(int, input().strip().split(" ")))
 
def prime(n):
    for j in range(2, n):
        if n % j == 0:
            return False
    return True
 
def primes_under(n, arr):
    for i in range(2, n+1):
        if prime(i):
            arr.append(i)
 
arr = []
count = 0
primes_under(n, arr)
for a in arr:
    for (idx, p) in enumerate(arr):
        if idx > 0:
            if p + arr[idx-1] + 1 == a:
                count += 1
            
if count >= k:
    print("YES")
else:
    print("NO")