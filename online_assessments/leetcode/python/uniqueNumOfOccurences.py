# Source: https://leetcode.com/problems/unique-number-of-occurrences/
from typing import List
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        myDict = {}
        for i in arr:
            if myDict.get(str(i)):
                myDict[str(i)] += 1
            else:
                myDict[str(i)] = 1

        compressedDict = {}
        for _, value in myDict.items():
            if compressedDict.get(str(value)):
                return False
            else:
                compressedDict[str(value)] = 1

        return True


soln = Solution()

nums = [1,2,2,1,1,3]
ans = True
print("Input : " + str(nums))
print("Ans : " + str(ans))
result = soln.uniqueOccurrences(nums)
if result != ans:
    print("FAILED TEST 1 : " +  str(result))
else:
    print("Success Test 1 : " + str(result))

nums = [1,2]
ans = False
print("Input : " + str(nums))
print("Ans : " + str(ans))
result = soln.uniqueOccurrences(nums)
if result != ans:
    print("FAILED TEST 2 : " +  str(result))
else:
    print("Success Test 2 : " + str(result))