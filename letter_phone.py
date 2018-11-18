letters={0:'0', 1:'1', 2:'abc', 3:'def', 4:'ghi', 5:'jkl', 6:'mno', 7:'pqrs', 8:'tuv', 9:'wxyz'}
def letterCombinations(A):
	#letters={1:'', 2:'abc', 3:'def', 4:'ghi', 5:'jkl', 6:'mno', 7:'pqrs', 8:'tuv', 9:'wxyz'}
	A=list(A)
	#print(A)
	result=[]
	
	
	def recurse(n,cur):
		if not n:
			result.append(cur)
			return
		for l in letters[int(n[0])]:
			#print(l)
			recurse(n[1:],cur+l)
	recurse(A,"")
	result = sorted(result)
	return result

print(letterCombinations("243"))