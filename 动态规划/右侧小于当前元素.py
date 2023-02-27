from typing import *
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        ...
        resultlist = nums[:]
        resultlist[0] = sum((1 for i in nums[1:] if i < nums[0]))
        for i in range(1,len(nums)):
            if nums[i] < nums[i-1]:
                resultlist[i] = resultlist[i-1]-1
            else:
                resultlist[i] = resultlist[i-1]
        return resultlist 
a = Solution()
print(a.countSmaller([5,2,6,1]))