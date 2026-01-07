# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        subTreeSum = []

        def DFS(root):
            if not root:
                return 0

            total = DFS(root.left) + DFS(root.right) + root.val
            subTreeSum.append(total)

            return total

        total_sum = DFS(root)
        max_prod = 1

        for s in subTreeSum:
            max_prod = max(max_prod, s * (total_sum - s))

        return max_prod % (10**9 + 7)
