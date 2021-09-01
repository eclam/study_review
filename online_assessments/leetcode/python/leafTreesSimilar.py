# Source : https://leetcode.com/problems/leaf-similar-trees/submissions/
class Solution:
    def traverseTree(self, root) -> List[int]:
        if root is None:
            return None
        left = self.traverseTree(root.left)
        right = self.traverseTree(root.right)

        if left is None and right is None:
            return [root.val]
        elif left is None and right is not None:
            return right
        elif left is not None and right is None:
            return left
        elif left is not None and right is not None:
            return left + right

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        arrRoot1 = self.traverseTree(root1)
        arrRoot2 = self.traverseTree(root2)

        if arrRoot1 is None or arrRoot2 is None or len(arrRoot2) != len(arrRoot1):
            return False

        for i, val in enumerate(arrRoot1):
            if val != arrRoot2[i]:
                return False
        return True