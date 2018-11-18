def least_rotation(s):
	s += s      # Concatenate string to it self to avoid modular arithmetic
	f = [-1] * len(s)     # Failure function
	k = 0       # Least rotation of string found so far
	for j in range(1,len(s)):
		sj = s[j]
		i = f[j-k-1]
		while i != -1 and sj != s[k+i+1]:
			if sj < s[k+i+1]:
				k = j-i-1
			i = f[i]
		if sj != s[k+i+1]: # if sj != s[k+i+1], then i == -1 
			if sj < s[k]: # k+i+1 = k
				k = j
			f[j-k] = -1
		else:
			f[j-k] = i+1
	print(k)

least_rotation("kaabaaac")