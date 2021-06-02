"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3749/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
"""

def make_binary_tree_from_array(arr):
    if len(arr) < 1: return None

    node = TreeNode(arr[0])

    if len(arr) == 1:
        return node
    elif len(arr) == 2:
        node.left = TreeNode(arr[1])
        return node
    elif len(arr) == 3:
        node.left = TreeNode(arr[1])
        node.right = TreeNode(arr[2])
        return node

    if arr[1] is None and arr[2] is None:
        return node
    elif arr[2] is None:
        rest = arr[1:2] + arr[3:]
        node.left = make_binary_tree_from_array(rest)
    elif arr[1] is None:
        rest = arr[2:]
        node.right = make_binary_tree_from_array(rest)
    else:
        # divide rest array into two subarray
        l_rest = []
        r_rest = []
        x = 0
        cnt = 0
        cnt_len = 0
        for i in range(1, len(arr)):
            if cnt == 0:
                x += 1
                cnt = 2 ** x
                cnt_len = 2 ** x
            if cnt > int(cnt_len / 2):
                l_rest.append(arr[i])
            else:
                r_rest.append(arr[i])
            cnt -= 1
        node.left = make_binary_tree_from_array(l_rest)
        node.right = make_binary_tree_from_array(r_rest)
    return node


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # brute-force: inorder traverse w/level
    def levelOrder(self, root):
        level_dict = {}
        def traverse(node, level):
            if node is None or node.val is None: return None
            if level not in level_dict:
                level_dict[level] = []
            level_dict[level].append(node.val)
            traverse(node.left, level + 1)
            traverse(node.right, level + 1)
        traverse(root, 0)
        return list(level_dict.values())

"""
solution = Solution()
print(solution.levelOrder(make_binary_tree_from_array([3,9,20,None,None,15,7]))) # [[3],[9,20],[15,7]]
print(solution.levelOrder(make_binary_tree_from_array([1]))) # [[1]]
print(solution.levelOrder(make_binary_tree_from_array([]))) # []

print(solution.levelOrder(make_binary_tree_from_array(list(range(20)))))
# [[0], [1, 2], [3, 4, 5, 6], [7, 8, 9, 10, 11, 12, 13, 14], [15, 16, 17, 18, 19]]
print(solution.levelOrder(make_binary_tree_from_array(list(range(1000)))))
# ?
print(solution.levelOrder(make_binary_tree_from_array(list(range(2000)))))
# ?
"""
