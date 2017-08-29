class Solution(object):
    
    # # hash map and heap: O(NlogK) time, O(k) space 
    # def leastInterval(self, tasks, n):
    #     """
    #     :type tasks: List[str]
    #     :type n: int
    #     :rtype: int
    #     """
    #     count, heap = {}, []
    #     for task in tasks:
    #         count[task] = count.get(task, 0) + 1
    #     for task, cnt in count.items():   
    #         heapq.heappush(heap, (-cnt, task))  # priority queue
    #     time = 0
    #     while heap:
    #         temp = []  # temperily store tasks that has been scheduled
    #         for i in xrange(0, n + 1):   # one period = n + 1
    #             if not heap and not temp:   # bug: forget to check temp 
    #                 break
    #             time += 1
    #             if heap:   # bug: check whether heap is empty -> idle
    #                 cnt_neg, task = heapq.heappop(heap)
    #                 if cnt_neg < -1:
    #                     temp.append((cnt_neg + 1, task))
    #         for elem in temp:
    #             heapq.heappush(heap, elem)
    #     return time
    
    # (more elegant) hash map and heap: O(NlogK) time, O(k) space 
    def leastInterval(self, tasks, n):
        count, heap = {}, []
        for task in tasks:
            count[task] = count.get(task, 0) + 1
        for task, cnt in count.items():   
            heapq.heappush(heap, -cnt)  # priority queue
        time = 0
        while heap:
            temp = []  # temporarily store tasks that has been scheduled
            for i in xrange(0, n + 1):   # one interval period = n + 1
                if not heap and not temp:   # bug: forget to check temp 
                    break
                time += 1
                if heap:   # bug: check whether heap is empty -> idle
                    cnt_neg = heapq.heappop(heap)
                    if cnt_neg < -1:
                        temp.append(cnt_neg + 1)
            for elem in temp:
                heapq.heappush(heap, elem)
        return time
                
        