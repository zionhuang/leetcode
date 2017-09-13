#U P L R分别代表上下左右
#给一个字符串moves='UPLRUU'这样的，判断是否会回到原点

class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        return moves.count('L') == moves.count('R') and moves.count('U') == moves.count('D')
        
        