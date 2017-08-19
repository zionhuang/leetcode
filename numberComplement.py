'''
思路：比如5大的最小2的幂是8，5异或（8-1）就是结果
我自己写的是下面这个，虽然代码也算简洁，但是速度很慢
我估计是bin和len这里很不太好
return (2**(len(bin(num))-2)-1)^num
#因为bin(num)后的字符串带0b，然后才是二进制数，所以有个减二
这里找到这些“8”们是关键，看了别人的算法里用了位操作
'''

class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        i = 1
        while i <= num:
            i <<= 1 #i=2 4 8 16 ........
            #这个找最小2的n次方的方法比较好
        return (i-1) ^ num

num = 5
solution = Solution()
print(solution.findComplement(num))