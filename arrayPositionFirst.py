'''
比如 1 3 5 7四个数，如果 （1，3） 和（5，7）那结果是6
如果是（1，7）和（3，5）结果为4
我总结的就是：小的就尽量在一起，可以把小的数尽可能多埋掉
所以，做法就是，先排序，所以至少nlogn复杂度，
然后把所有index为偶数的加起来就是所得
'''

'''我第一遍的垃圾方法
        nums.sort()
        sum = 0
        for i in xrange(len(nums)):
            if i % 2 == 0:
                sum += nums[i]
        return sum
'''

class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #return sum(nums.sort()[::2])
        #这里又忘了一点，数组的sort方法是不返回值的，应该用sorted
        return sum(sorted(nums)[::2])

nums = [1,3,2,4]
solution = Solution()
print(solution.arrayPairSum(nums))