# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        q = deque()
        q.append(root)
        maxi = float('-inf')
        level = 1
        ans = 0

        while q:
            total = 0
            n = len(q)
            
            for _ in range(n):
                current = q.popleft()
                total += current.val
                if current.left:
                    q.append(current.left)
                if current.right:
                    q.append(current.right)

            if maxi < total:
                maxi = total
                ans = level
            level += 1
    
        return ans