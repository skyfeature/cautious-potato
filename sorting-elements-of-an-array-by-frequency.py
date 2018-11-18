t = int(input())
for i in range(t):
	n = int(input())
	ar = list(map(int, input().split()))
	count_dict = {}
	for c in ar:
		if c in count_dict:
			count_dict[c] += 1
		else:
			count_dict[c] = 1
	new_ar = [[freq, val] for freq, val in zip(count_dict.values(), count_dict.keys())]
	new_ar.sort(key=lambda x: (-x[0], x[1]))
	sorted_ar = []
	for c in new_ar:
		sorted_ar += [c[1] for i in range(c[0])]
	sorted_ar = ' '.join(map(str, sorted_ar))
	print(sorted_ar)