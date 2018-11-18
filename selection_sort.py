ar = [8, 4, 9, 8, 10, 3, 6, 1]

for i in range(len(ar)):
	min_ele = 1000000
	min_ele_index = -1
	for j in range(i, len(ar)):
		if (min_ele > ar[j]):
			min_ele = ar[j]
			min_ele_index = j
	ar[i], ar[min_ele_index] = ar[min_ele_index], ar[i]

print(ar)

