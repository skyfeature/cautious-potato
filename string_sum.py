def remove_left(K):
    for i in range(len(K)):
        if int(K[i]):
            return K[i:]
    return "0"


def addition(P, Q):
    carry = 0
    ans_add = ""
    min_len = min(len(P), len(Q))
    for i in range(min_len-1, -1, -1):
        ans_add = str((carry + int(P[i]) + int(Q[i]))%10) + ans_add
        carry = (carry + int(P[i]) + int(Q[i]))//10
    if carry:
        ans_add = str(carry) + ans_add
    
    return ans_add

print(remove_left(addition("228", "6840"))

