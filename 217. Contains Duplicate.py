#!/usr/bin/python

def containsDuplicate(nums):
    table = {}        # dictionary to store the iterated element
    for i in nums:
        if (table.has_key(i)):
            return False
        else:
            table[i] = 1
           
    return True
    
if __name__ == '__main__':
    test = [1,2,3,4,5]
    if(containsDuplicate(test)):
        print "true"
       
