#!/usr/bin/python

def twoSum_Brute_force(nums, target):
	for i in range(len(nums)):
		for j in range(i + 1, len(nums)):
			if nums[i] + nums[j] == target:
				print i, " ", j 	# output 
				return [i, j]
				
def twoSum_Hash_map(nums, target):
	myMap = {}						# hash map
	for i in range(len(nums)):
		implement = target - nums[i]
		if myMap.has_key(implement):
			print myMap[implement], " ", i
			return [myMap[implement], i]
		else:
			myMap[nums[i]] = i

if __name__ == '__main__':
	nums = [3,2,4] 					# [2, 7, 11, 15]
	target = 6     					#  9
	twoSum_Hash_map(nums, target)
	