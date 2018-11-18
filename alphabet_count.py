

def count(a):
	if (a <= 0):
		return 0
	if (dp[a] != -1):
		return dp[a]
	r = a%10
	rr = a%100
	# print(a)
	# a = a//10
	if (r != 0) and (10 <= rr <= 26):
		dp[a] = 2 + count(a//10)
	elif (r != 0):
		dp[a] = 1 + count(a//10)
	elif (0 < rr <= 26):
		dp[a] = 1 + count(a//10)
	return dp[a]

dp = [-1 for i in range(20+1)]
print(count(20))