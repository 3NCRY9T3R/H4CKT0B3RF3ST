# This function checks if a string is a palindrome
def isPalindrome(s):
	return s == s[::-1]


# Driver code
s = "malayalam"
result = isPalindrome(s)

if result:
	print("Yes")
else:
	print("No")
