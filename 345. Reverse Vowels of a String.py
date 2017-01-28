#!/usr/bin/python

def reverseVowels(s):
	vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
	answer = []			# the reverse string
	target = []			# found vowels in s
	for i in range(len(s)):
#		print i, " ", s[i]
		if s[i] in vowels:
#			print "found ", s[i]
			target.append(s[i])
			answer.append('\0x')		# save the seats for the found vowels
		else:
			answer.append(s[i])
	
	reverseCount = len(target) - 1
	for i in range(len(s)):
		if answer[i] == '\0x':
			answer[i] = target[reverseCount]
			reverseCount -= 1
		
	print "".join(answer)
	return "".join(answer)
		
		
if __name__ == "__main__":
	str = 'leetcode'
	reverseVowels(str)
