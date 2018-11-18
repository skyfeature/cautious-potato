grid = [[9, 6, 5, 2],
		[8, 7, 6, 5],
		[7, 3, 1, 6],
		[1, 1, 1, 7]]

n = len(grid)
m = len(grid[0])

def maxSequence(grid):
	dp = [[0 for i in range(m)] for j in range(n)]
	dp[0][0] = 1
	for j in range(1, m):
		if (abs(grid[0][j] - grid[0][j-1]) == 1):
			dp[0][j] = 1+ dp[0][j-1]
		else:
			break

	for i in range(1, n):
		if (abs(grid[i][0] - grid[i-1][0]) == 1):
			dp[i][0] = 1 + dp[i-1][0]
		else:
			break

	for i in range(1, n):
		for j in range(1, m):
			if (abs(grid[i][j]-grid[i-1][j]) == 1) and (abs(grid[i][j]-grid[i][j-1]) == 1):
				dp[i][j] = 1+max(dp[i-1][j], dp[i][j-1])
			elif (abs(grid[i][j]-grid[i-1][j]) == 1):
				dp[i][j] = 1+dp[i-1][j]
			elif (abs(grid[i][j]-grid[i][j-1]) == 1):
				dp[i][j] = 1+dp[i][j-1]

	max_n = -1
	for i in range(n):
		for j in range(m):
			max_n = max(max_n, dp[i][j]);
	print(dp)
	return max_n

print(maxSequence(grid))