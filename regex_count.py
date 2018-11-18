s1 = "aaabbaaabb"
s2 = "aa*b"

A = []
B = []

a, b = s2.split('*')
a_len = len(a)
b_len = len(b)

for i in range(len(s1)):
	if (s1[i:i+a_len] == a):
		A.append(i)
	elif (s1[i:i+b_len] == b):
		B.append(i)

print(A, B)

ans = 0
for i in range(len(A)):
	for j in range(len(B)):
		if (A[i]+a_len <= B[j]):
			ans += (len(B)-j)
			break
print(ans)