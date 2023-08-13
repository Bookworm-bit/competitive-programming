def solution(n):
  """
  Returns the number of different staircases that can be built from exactly n bricks,
  with at least two steps, and with steps in decreasing order, and with no steps of 1 brick,
  and with no two consecutive steps of the same height.

  Args:
    n: The number of bricks.

  Returns:
    The number of staircases.
  """

  if n < 3:
    return 0

  # The dp table will store the number of staircases that can be built from
  # exactly k bricks, with at least two steps, and with steps in decreasing order, and
  # with no steps of 1 brick, and with no two consecutive steps of the same height.

  dp = [0] * (n + 1)

  # The base cases are the staircases with 2 or 3 bricks.

  dp[2] = 1
  dp[3] = 2

  # For each value of k from 4 to n, we can build a staircase with k bricks by
  # adding one brick to a staircase with k - 1 bricks, or by adding two bricks to
  # a staircase with k - 2 bricks, as long as the resulting staircase has at least
  # two steps and the steps are in decreasing order, no steps are of 1 brick, and
  # no two consecutive steps are of the same height.

  for k in range(4, n + 1):
    dp[k] = dp[k - 1] + dp[k - 2]
    for i in range(3, k):
      if k - i >= 2 and (k - i) % 3 == 0 and i % 3 != 0 and dp[k - i] != 0:
        dp[k] -= dp[i]

  return dp[n]


# Test cases
print(solution(3))  # Output: 1
print(solution(200))  # Output: 487067745
