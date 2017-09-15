# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        if 1 == len(nums):
            return TreeNode(nums[0])
        index = self.findMax(nums)
        root = TreeNode(nums[index])
        root.left = self.constructMaximumBinaryTree(nums[0:index])
        root.right = self.constructMaximumBinaryTree(nums[index+1:])
        return root

        
        
    def findMax(self, array):
        maxNum = array[0]
        index = 0
        for i in range(len(array)):
            if array[i] > maxNum:
                maxNum = array[i]
                index = i
        return index