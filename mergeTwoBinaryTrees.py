'''
把两棵二叉树合并
规则如下：
从根开始，所有的结点，两棵树都有的结点直接加，
一个有一个没有的，用有的那个去填，都没有的就都没有
'''
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if not t1:
            return t2
        if not t2:
            return t1
        res = TreeNode(t1.val + t2.val)
        res.left = self.mergeTrees(t1.left, t2.left)
        res.right = self.mergeTrees(t1.right, t2.right)
        return res
    
//树1：1 3 2 5    
t1 = TreeNode(1)
t1.left = TreeNode(3)
t1.right = TreeNode(2)
t1.left.left = TreeNode(5)

//树2：2 1 3 null 4 null 7
t2 = TreeNode(3)
t2.left = TreeNode(1)
t2.right = TreeNode(3) 
t1.left.right = TreeNode(4)
t2.right.right = TreeNode(7) 

solution = Solution()
res = solution.mergeTrees(t1,t2)

//有空写个层序遍历输出


      