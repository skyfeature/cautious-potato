t = int(input())

def knapsack(w, values, weights, dp):
	is_w_too_small = 1
	for i in range(len(weights)):
		if w >= weights[i]:
			is_w_too_small = 0
	if (is_w_too_small):
		return 0
	if (dp[w] != -1):
		return dp[w]
	else:
		temp = -100000
		for i in range(len(weights)):
			if weights[i] <= w:
				temp = max(temp, values[i] + knapsack(w - weights[i], values[:i]+values[i+1:], weights[:i]+weights[i+1:], dp))
				# print("this", i, weights[i], w, temp)
		dp[w] = temp
		return dp[w]

for i in range(t):
	n = int(input())
	w = int(input())
	values = list(map(int, input().split()))
	weights = list(map(int, input().split()))
	dp = [-1 for i in range(w+1)]
	print(knapsack(w, values, weights, dp))
	print(dp)



'''
2
3
4
1 2 3
4 5 1
58
41
57 95 13 29 1 99 34 77 61 23 24 70 73 88 33 61 43 5 41 63 8 67 20 72 98 59 46 58 64 94 97 70 46 81 42 7 1 52 20 54 81 3 73 78 81 11 41 45 18 94 24 82 9 19 59 48 2 72
83 84 85 76 13 87 2 23 33 82 79 100 88 85 91 78 83 44 4 50 11 68 90 88 73 83 46 16 7 35 76 31 40 49 65 2 18 47 55 38 75 58 86 77 96 94 82 92 10 86 54 49 65 44 77 22 81 52


3
223
'''