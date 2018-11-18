t = int(input())
for i in range(t):
	n = int(input())
	a = [0, 0, 0]
	temp = list(map(int, input().split()))
	for c in temp:
		a[c] += 1
	ans = ["0" for i in range(a[0])] + ["1" for i in range(a[1])] + ["2" for i in range(a[2])]
	print((" ").join(ans))