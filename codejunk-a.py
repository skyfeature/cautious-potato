s = 'asdfaswdf'
a = {}
for c in s:
	if c in a:
		a[c] += 1
	else:
		a[c] = 1

ar = []
for (i, j) in zip(a.keys(), a.values()):
	if (j%2):
		print("No palindrom")
		break
	ar.append([i, j])
ar.sort()
print(ar)
smallest_pal = ''
for k in range(len(ar)):
	i, j = ar[k]
	smallest_pal += i*(j//2)

for k in range(len(ar)-1, -1, -1):
	i, j = ar[k]
	smallest_pal += i*(j//2)
	
print(smallest_pal)