#!/usr/bin/python
# -*- coding: <utf-8> -*-

def reverseString(s):
	if len(s) == 0:
		return s
	answer = ""
	iterator = len(s) - 1
	for i in range(len(s)):
		answer += s[iterator]
		iterator -= 1
	print type(answer)
	return answer

if __name__ == '__main__':
	print reverseString("hello")

