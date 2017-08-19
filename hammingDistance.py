'''
汉明距是之前在计算机网络里面就接触到的概念，这个距离简单来说就是把两个int数
转换成二进制数之后，从低位开始对比所有bit位上有多少位是不同的，
这个性质用异或很好求，异或就是相同取0不同取1，
所以，我们直接把两个int用xor作异或操作之后，用bin转换成二进制string，
再计算这个string中1的个数，用python非常简洁的实现
'''
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        return bin(x^y).count('1')


x = 30 # x = 11110
y = 5  # y = 00101

solution = Solution()
result = solution.hammingDistance(x, y)
print(result)