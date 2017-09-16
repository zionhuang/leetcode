'''
暴力方法
'''
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        return [bin(i).count('1') for i in range(num+1)]
'''
怎么得到一个数的二进制中的1的数量
这个地方是可以优化的
一个数二进制的1的个数 = 该数&该数的前一个数的结果的那个数的1的个数加1
'''
'''
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ret = range(num+1)
        for i in ret[1::]:
            ret[i] = ret[i&(i-1)] + 1
        return ret
'''

