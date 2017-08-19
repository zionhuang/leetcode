'''
3sum问题是典型的two point题
'''
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        length = len(nums)
        res = []
        i = 0
        j = i+1
        k = length -1
        while i<length-2:
            j = i + 1
            k = length -1
            while j<k:
                temp = nums[i]+nums[j]+nums[k]
                if temp == 0:
                    res.append([nums[i],nums[j],nums[k]])
                    j += 1
                    k -= 1
                    while k>j and nums[k] == nums[k+1]:
                        k -= 1
                    while k>j and nums[j] == nums[j-1]:
                        j += 1
                elif temp>0:
                    k -= 1
                    while k>j and nums[k] == nums[k+1]:
                        k -= 1
                else:
                    j += 1
                    while k>j and nums[j] == nums[j-1]:
                        j += 1
            i += 1
            while i<length-2 and nums[i]==nums[i-1]:
                i += 1
        return res
'''
我考虑过，但没实现出来的一个思路
考虑正负，零的个数等,当时可能字典用的不熟，没做好
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        fre = {}
        for num in nums:
            fre[num] = fre.get(num, 0) + 1
        unique_nums = fre.keys()
        pos = sorted([x for x in unique_nums if x >= 0])
        neg = sorted([x for x in unique_nums if x < 0], reverse = True)
        if fre.get(0, 0) >= 3:
            ans.append([0, 0, 0])
        for p in pos:
            for n in neg:
                r = 0 - p - n
                if r in fre:
                    if (r == p or r == n) and fre[r] > 1:
                        ans.append([n, r, p])
                    elif r < n:
                        ans.append([r, n, p])
                    elif r > p:
                        ans.append([n, p, r])
        return ans  
'''