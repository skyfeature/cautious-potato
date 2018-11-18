# from itertools import permutations

# t = int(input())
# for i in range(t):
# 	s = input()
# 	s = ''.join(sorted(s))
# 	perms = [''.join(p) for p in permutations(s)]
# 	perms = sorted(list(set(perms)))
# 	print(' '.join(perms))

# 	

t = int(input())

def permute(s):
	if len(s) == 0:
		return 0
	elif len(s) == 1:
		return [s]
	else:
		temp_ar = set()
		for i in range(len(s)):
			for c in permute(s[:i] + s[i+1:]):
				temp_ar.add(s[i] + c)
		return list(temp_ar)

for i in range(t):
	s = input()
	print(sorted(permute(s)))