class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        res=""
        lis = [[""] * len(s) for _ in range(numRows)]
        x=0
        direction=1
        for i in range(len(s)):
            lis[x][i]=s[i]
            x+=direction
            if x == numRows-1: direction = -1
            if x ==0 : direction =1
        for i in range(numRows):
            res+="".join(lis[i])
        return res

