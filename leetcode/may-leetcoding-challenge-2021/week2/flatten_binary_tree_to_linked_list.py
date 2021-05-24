"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3742/

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 
Follow up: Can you flatten the tree in-place (with O(1) extra space)?
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flatten(self, root):
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None or (root.left is None and root.right is None):
            return root
        if root.right is None:
            root.right = self.flatten(root.left)
            root.left = None
        elif root.left is None:
            root.right = self.flatten(root.right)
        else:
            left = root.left
            while left.right:
                left = left.right
            left.right = self.flatten(root.right)
            root.right = self.flatten(root.left)
            root.left = None
        return root

"""
def tree_to_list(tree):
    if tree is None:
        return [None]
    return [tree.val] + tree_to_list(tree.left) + tree_to_list(tree.right)

solution = Solution()
print(tree_to_list(solution.flatten(TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(4)), TreeNode(5, None, TreeNode(6)))))) # [1,null,2,null,3,null,4,null,5,null,6]
print(tree_to_list(solution.flatten(None))) # []
print(tree_to_list(solution.flatten(TreeNode(0)))) # [0]
"""
