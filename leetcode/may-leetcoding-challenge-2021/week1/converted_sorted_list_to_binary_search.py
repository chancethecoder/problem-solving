"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3733/

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedListToBST(self, head):
        # make linked list to array
        arr = []
        while head is not None:
            arr.append(head.val)
            head = head.next

        # define function
        def sortedArrayToBST(arr):
            if not arr:
                return None
            mid = len(arr) // 2
            root = TreeNode(arr[mid])
            root.left = sortedArrayToBST(arr[:mid])
            root.right = sortedArrayToBST(arr[mid+1:])
            return root

        return sortedArrayToBST(arr)

"""
solution = Solution()
print(solution.sortedListToBST(ListNode(-10, ListNode(-3, ListNode(0, ListNode(5, ListNode(9)))))))
print(solution.sortedListToBST(None))
print(solution.sortedListToBST(ListNode(0)))
print(solution.sortedListToBST(ListNode(1, ListNode(3))))
"""