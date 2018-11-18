t = int(input())
for i in range(t):
	ar = list(input().split('.'))
	ar = ar[::-1]
	s = '.'.join(ar)
	print(s)