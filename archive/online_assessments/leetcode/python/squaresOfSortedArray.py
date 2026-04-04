# Source : https://leetcode.com/problems/squares-of-a-sorted-array/
from typing import List
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        resultNums = [i**2 for i in nums]
        resultNums.sort()
        return resultNums



soln = Solution()

nums = [-4,-1,0,3,10]
print("Input : " + str(nums))
ans = [0,1,9,16,100]
print("Ans : " + str(ans))
result = soln.sortedSquares(nums)
if result != ans:
    print("FAILED TEST 1 : " +  str(result))
else:
    print("Success Test 1 : " + str(result))

nums = [-7,-3,2,3,11]
print("Input : " + str(nums))
ans = [4,9,9,49,121]
print("Ans : " + str(ans))
result = soln.sortedSquares(nums)
if result != ans:
    print("FAILED TEST 2 : " +  str(result))
else:
    print("Success Test 2 : " + str(result))