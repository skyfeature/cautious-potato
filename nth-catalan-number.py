t = int(input())


ar = [0 for i in range(101)]
ar[0] = 1

def nth_catalan_o_n2(n):
	if n != 0:
		for j in range(1, n+1):
			if not ar[j]:
				for k in range(j):
					ar[j] += ar[k]*ar[j-1-k]
	print(ar[n])


def eff_bino_coeff(n, k):
	if k > n-k:
		k = n-k
	ans_n = 1
	ans_d = 1
	for i in range(k):
		ans_n *= (n-i)
		ans_d *= i+1
	return ans_n/ans_d

def nth_catalan_o_n(n):
	print(int(eff_bino_coeff(2*n, n)/(n+1)))

for i in range(t):
	n = int(input())
	nth_catalan_o_n(n)
	# nth_catalan_o_n2(n)