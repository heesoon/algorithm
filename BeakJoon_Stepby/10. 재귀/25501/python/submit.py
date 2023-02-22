import sys

def recursive(s, l, r):
    if l >= r: return [1, l+1]
    elif s[l] != s[r] : return [0, l+1]
    else: return recursive(s, l+1, r-1)

def isPalindrome(s):
    return recursive(s, 0, len(s)-1)

#print('ABBA: ', isPalindrome('ABBA'))
#print('ABC: ', isPalindrome('ABC'))

#a, b = isPalindrome('ABBA')
#print('ABBA: ', a, b)

T = int(sys.stdin.readline())

for i in range(T):
    S = str(sys.stdin.readline().rstrip())
    a, b = isPalindrome(S)
    print(a, b)