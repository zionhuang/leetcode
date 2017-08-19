'''
开始用了字典，效率不是很高，用set可以有很好的效果，而且逻辑清晰
ython中set的一些使用方法还是很有技巧的
a=set('abc') b=set('abcd')
a<b是对的  a-b==set()   b-a==set(d)也都是对的
但是如果a=set('abe')那这些就不成立了
所以这个可以好好利用
'''
'''第一次'''
'''
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        dic = {'Q':1,'q':1,'W':1,'w':1,'E':1,'e':1,'R':1,'r':1,'T':1,'t':1,'Y':1,'y':1,
               'U':1,'u':1,'I':1,'i':1,'O':1,'o':1,'P':1,'p':1,
               'A':2,'a':2,'s':2,'S':2,'D':2,'d':2,'F':2,'f':2,'G':2,'g':2,
               'H':2,'h':2,'J':2,'j':2,'K':2,'k':2,'L':2,'l':2,
              'z':3,'Z':3,'X':3,'x':3,'C':3,'c':3,'V':3,'v':3,'B':3,
              'b':3,'N':3,'n':3,'M':3,'m':3}
        res = []
        for i in words:
            first = dic[i[0]]
            for j in xrange(len(i)):
                if dic[i[j]] != first:
                    break
                if j == len(i)-1:
                    res.append(i)
        return res
'''

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1 = 'qwertyuiopQWERTYUIOP'
        row2 = 'asdfghjklASDFGHJKL'
        row3 = 'zxcvbnmZXCVBNM'
        res = []
        for i in words:
            if len(set(i+row1))==len(row1) or len(set(i+row2))==len(row2) or len(set(i+row3))==len(row3):
                res.append(i)
        return res