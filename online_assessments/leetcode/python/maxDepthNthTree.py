# Source: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        depth = 0
        if root:
            for i in root.children:
                temp = self.maxDepth(i)
                if temp > depth:
                    depth = temp

            return depth + 1
        return depth
