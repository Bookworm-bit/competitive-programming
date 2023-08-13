def solution(l, t):
    left = 0
    right = 0
    current_sum = 0

    while right <= len(l):
        if current_sum == t:
            return [left, right - 1]
        
        if current_sum < t:
            if right < len(l):
                current_sum += l[right]
            right += 1
        else:
            current_sum -= l[left]
            left += 1

    return [-1, -1]

# Test cases
print(solution([1, 2, 3, 4], 15))  # Output: [-1, -1]
print(solution([4, 3, 10, 2, 8], 12))  # Output: [2, 3]
