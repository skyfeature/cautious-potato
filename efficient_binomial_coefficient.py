#Incorrect due to floating point error
def eff_bino_coeff(n, k):
	if n < k:
		return 0
	if k > n-k:
		k = n-k
	ans = 1
	for i in range(1, k+1):
		ans *= (n-i+1)
		ans /= i
	return ans


t = int(input())
for i in range(t):
	n, r = list(map(int, input().split()))
	print(int(eff_bino_coeff(n, r)))