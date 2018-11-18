ar = [4, 7, 6, -2, 8, 9]
# ar = list(map(int, input().split()))
n = len(ar)
dp = [-1 for i in range(n+1)]
# def f(n):
# 	if (n == 1):
# 		return ar[0]
# 	elif (n == 2):
# 		return max(ar[0], ar[1])
# 	elif (dp[n] != -1):
# 		return dp[n]
# 	dp[n] = max(ar[n-1] + f(n-2), f(n-1))
# 	return dp[n]
# print(f(n))


def f(n):
	if (n == 1):
		return ar[0]
	elif (n == 2):
		return max(ar[0], ar[1])
	dp[1] = ar[0]
	dp[2] = max(ar[0], ar[1])
	for i in range(3, n+1):
		dp[i] = max(ar[i-1] + dp[i-2], dp[i-1])
	return dp[n]

print(f(n))