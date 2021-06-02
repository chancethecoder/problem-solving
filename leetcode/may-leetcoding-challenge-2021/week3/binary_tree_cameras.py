"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3745/

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
"""

def make_binary_tree_from_depth(depth):
    node = TreeNode(0)
    if depth > 0:
        node.left = make_binary_tree_from_depth(depth - 1)
        node.right = make_binary_tree_from_depth(depth - 1)
    return node

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

# ----------------------------------------------------------------

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # brute-force: get depth and count even/odd nodes
    # def minCameraCover(self, root):

    #     def get_max_depth(node, curr_depth):
    #         if node is None:
    #             return curr_depth
    #         else:
    #             left_depth = get_max_depth(node.left, curr_depth + 1) if node.left else curr_depth
    #             right_depth = get_max_depth(node.right, curr_depth + 1) if node.right else curr_depth
    #             return max(left_depth, right_depth)

    #     def count_by_depth(node, curr_depth, max_depth):
    #         if node is None:
    #             return 0
            
    #         if (curr_depth % 2) == (max_depth % 2):
    #             left_count = count_by_depth(node.left, curr_depth + 1, max_depth)
    #             right_count = count_by_depth(node.right, curr_depth + 1, max_depth)
    #             return left_count + right_count
    #         else:
    #             left_count = count_by_depth(node.left, curr_depth + 1, max_depth)
    #             right_count = count_by_depth(node.right, curr_depth + 1, max_depth)
    #             return left_count + right_count + 1

    #     max_depth = get_max_depth(root, 0)

    #     return count_by_depth(root, 0, max_depth) if max_depth > 0 else 1

    # brute-force: greedy dfs
    def minCameraCover(self, root):

        def count_min(node, par = None, covered = {None}):
            if node is None:
                return 0

            ret = 0
            ret += count_min(node.left, node, covered)
            ret += count_min(node.right, node, covered)

            # root case
            if par is None and node not in covered:
                covered.update({ node, par, node.left, node.right })
                return ret + 1

            # cover this node if one of children not covered
            if node.left not in covered or node.right not in covered:
                covered.update({ node, par, node.left, node.right })
                return ret + 1

            return ret

        return count_min(root)

"""
solution = Solution()
print(solution.minCameraCover(make_binary_tree_from_array([0]))) # 1
print(solution.minCameraCover(make_binary_tree_from_array([0, 0, 0]))) # 1
print(solution.minCameraCover(make_binary_tree_from_array([0, 0, None, 0, 0]))) # 1
print(solution.minCameraCover(make_binary_tree_from_array([0, 0, 0, 0, 0, 0, 0]))) # 2
print(solution.minCameraCover(make_binary_tree_from_array([0, 0, None, 0, None, None, 0]))) # 2
print(solution.minCameraCover(make_binary_tree_from_array([0, None, 0, 0, 0, None, None, None, 0]))) # 2

print(solution.minCameraCover(make_binary_tree_from_depth(1))) # 1
print(solution.minCameraCover(make_binary_tree_from_depth(2))) # 2
print(solution.minCameraCover(make_binary_tree_from_depth(6))) # 42
print(solution.minCameraCover(make_binary_tree_from_depth(8))) # 170
print(solution.minCameraCover(make_binary_tree_from_depth(10))) # 682
"""
