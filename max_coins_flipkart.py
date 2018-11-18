dim = [1, 5, 10, 25]
inp = [99, 98, 0, 0, 1]
dummy = [0, 0, 0, 0]

def geedy(price, p, q, r, s):
	if (price <= p):
		return [price, 0, 0, 0]
	price -= p
	if (price <= 5*q):
		if (price%5 == 0):
			return [p, price/5, 0, 0]
		return [0, 0, 0, 0]
	price-=5*q
	if (price <= 10*r):
		if (price%10 == 0):
			return [p, q, price/10, 0]
		return [0, 0, 0, 0]
	if (price <= 25*s):
		if (price%25 == 0):
			return [p, q, r, price/25]
		return [0, 0, 0, 0]
	return [0, 0, 0, 0]

def getMaxCoins(price, p, q, r, s):
	max_count = -1
	ans_list = [0, 0, 0, 0]
	for i in range(25):
		for j in range(5):
			for k in range(3):
				if (p >= i and q >= j and r >= k):
					counts = geedy(price, p-i, q-j, r-k, s)
					if (counts != dummy):
						# print(counts)
						count = sum(counts)
						if (count > max_count):
							max_count = count
							ans_list = counts

	if max_count == -1:
		return dummy
	return ans_list

print(getMaxCoins(99, 98, 0, 0, 1))



