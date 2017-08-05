class Solution(object):
    
    # brute force: O(mn) time,  O(min(m,n)) space
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        ret, restaurant = float('inf'), []
        for i in xrange(len(list1)):
            for j in xrange(len(list2)):
                if list1[i] == list2[j]:
                    if i + j == ret:
                        restaurant.append(list1[i])
                    elif i + j < ret:
                        ret = i + j
                        restaurant = [list1[i]]
                    break
        return restaurant
    
    # hash table: O(m + n) time,  O(min(m,n)) space
    def findRestaurant(self, list1, list2):
        restaurants = {name: index for (index, name) in enumerate(list1)}
        ret, restaurant = float('inf'), []
        for i, name in enumerate(list2):
            if name in restaurants:
                indexSum = i + restaurants[name]
                if ret > indexSum:
                    ret = indexSum
                    restaurant = [name]
                elif ret == indexSum:
                    restaurant.append(name)
        return restaurant
                    
        